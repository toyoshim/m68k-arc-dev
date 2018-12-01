extern void main();
extern int* _ram_start;
extern int* _stack_top;

void __attribute__((weak)) main() {}

void _start() {
  int* ram;
  for (ram = _ram_start; ram < _stack_top; ram++)
    *ram = 0;
  main();
  _start();
}
