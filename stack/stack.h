#include <stdint.h>
#include <stdint.h>
typedef struct Stack {
  uint64_t pointer;
  uint64_t size;
  uint64_t *arr;
} stack;

stack *stack_create();
void stack_push(stack *s, uint64_t val);
uint64_t stack_pop(stack *s);
void stack_delete( stack *s);
