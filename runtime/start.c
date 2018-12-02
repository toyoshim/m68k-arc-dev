extern void main();
extern int _ram_start;
extern int _stack_top;
extern int _init_data_start;
extern int _data_start;
extern int _data_end;

void __attribute__((weak)) main() {}

void _start() {
  int* ram;
  for (ram = &_ram_start; ram < &_stack_top; ram++)
    *ram = 0;
  int* rom = &_init_data_start;
  for (ram = &_data_start; ram < &_data_end; ram++)
    *ram = *rom++;
  main();
  _start();
}
