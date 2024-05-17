#include <stdio.h>
#include <stdint.h>
#include "stack.h"

int main() {
  stack *s = stack_create();
  stack_push(s, 1);
  stack_push(s, 2);
  stack_push(s, 3);
  stack_push(s, 4);
  stack_push(s, 5);
  printf("%ld \n", stack_pop(s));
  printf("%ld \n", stack_pop(s));
  printf("%ld \n", stack_pop(s));
  printf("%ld \n", stack_pop(s));
  printf("%ld \n", stack_pop(s));
  printf("%ld \n", stack_pop(s));
  printf("%ld \n", stack_pop(s));
  
  return 0;
}
