#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

const char kCommandExpand[] = "expand";
const char kCommandSplit[] = "split";
const char kCommandHelp[] = "help";

void usage(const char* argv0, const char* command) {
  if (NULL == command) {
    fprintf(stderr, "Usage: %s <command>\n", argv0);
  } else if (!strcmp(kCommandExpand, command)) {
    fprintf(stderr, "Usage: %s expand <filename> <size>\n", argv0);
    fprintf(stderr,
        "Expands the specified file size to be the specified one.\n");
    exit(EXIT_FAILURE);
  } else if (!strcmp(kCommandSplit, command)) {
    fprintf(stderr,
        "Usage: %s split <filename> <even-filename> <odd-filename>\n", argv0);
    fprintf(stderr,
        "Splits the specified file into two files, one is for even bytes, the "
        "other is for odd bytes.\n");
    exit(EXIT_FAILURE);
  } else {
    fprintf(stderr, "Usage: %s help <command>\n", argv0);
    fprintf(stderr, "Shows detailed usages for the specified command.\n\n");
  }
  fprintf(stderr, "command:\n");
  fprintf(stderr, "  expand    expand binary file size\n");
  fprintf(stderr, "  split     split file into files for even and odd bytes\n");
  fprintf(stderr, "  help      show detailed usages\n");
  exit(EXIT_FAILURE);
}

int parse_int_arg(const char* arg, int* out_int_value) {
  int value = 0;
  if ('0' == arg[0] && arg[1])
    return 1;
  while (*arg) {
    if (*arg < '0' || '9' < *arg)
      return 1;
    value *= 10;
    value += *arg++ - '0';
  }
  *out_int_value = value;
  return 0;
}

int open_to_write(const char* filename) {
  return open(filename, O_APPEND | O_RDWR);
}

int open_to_create(const char* filename) {
  return open(filename, O_CREAT | O_RDWR, 0666);
}

int open_to_read(const char* filename) {
  return open(filename, O_APPEND | O_RDONLY);
}

void expand(int argc, char** argv) {
  int size;
  if (argc < 4 || parse_int_arg(argv[3], &size))
    usage(argv[0], argv[1]);
  int fd = open_to_write(argv[2]);
  if (fd < 0) {
    perror(argv[2]);
    exit(EXIT_FAILURE);
  }
  struct stat stat;
  if (fstat(fd, &stat) || stat.st_size > size) {
    fprintf(stderr, "filesize seems to be larger than %d\n", size);
    exit(EXIT_FAILURE);
  }
  size -= stat.st_size;
  char buf[4096];
  memset(buf, 0xff, 4096);
  while (size) {
    size_t write_size = size & 4095;
    if (!write_size)
      write_size = 4096;
    if (write_size != write(fd, buf, write_size))
      perror("write failure");
    size -= write_size;
  }
}

void split(int argc, char** argv) {
  if (argc < 5)
    usage(argv[0], argv[1]);

  int fd = open_to_read(argv[2]);
  if (fd < 0)
    perror(argv[2]);
  int even_fd = open_to_create(argv[3]);
  if (even_fd < 0)
    perror(argv[3]);
  int odd_fd = open_to_create(argv[4]);
  if (odd_fd < 0)
    perror(argv[4]);
  if (fd < 0 || even_fd < 0 || odd_fd < 0)
    usage(argv[0], argv[1]);

  struct stat stat;
  if (fstat(fd, &stat)) {
    perror(argv[2]);
    exit(EXIT_FAILURE);
  }
  size_t offset;
  for (offset = 0; offset < stat.st_size; offset += 8192) {
    uint8_t data[8192];
    size_t read_size = stat.st_size - offset;
    if (read_size > 8192)
      read_size = 8192;
    if (read_size != read(fd, data, read_size)) {
      perror(argv[2]);
      exit(EXIT_FAILURE);
    }
    uint8_t data_even[4096];
    uint8_t data_odd[4096];
    size_t write_size = read_size / 2;
    size_t i;
    for (i = 0; i < write_size; ++i) {
      data_even[i] = data[i * 2 + 0];
      data_odd[i] = data[i * 2 + 1];
    }
    if (write_size != write(even_fd, data_even, write_size)) {
      perror(argv[3]);
      exit(EXIT_FAILURE);
    }
    if (write_size != write(odd_fd, data_odd, write_size)) {
      perror(argv[4]);
      exit(EXIT_FAILURE);
    }
  }
}

void help(int argc, char** argv) {
  if (argc < 3)
    usage(argv[0], kCommandHelp);
  usage(argv[0], argv[2]);
}

int main(int argc, char** argv) {
  if (argc < 2)
    usage(argv[0], NULL);
  if (!strcmp(kCommandExpand, argv[1]))
    expand(argc, argv);
  else if (!strcmp(kCommandSplit, argv[1]))
    split(argc, argv);
  else if (!strcmp(kCommandHelp, argv[1]))
    help(argc, argv);
  else
    usage(argv[0], NULL);
  return 0;
}
