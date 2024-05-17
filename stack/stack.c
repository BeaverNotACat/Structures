#include "stack.h"
#include <stdint.h>
#include <stdlib.h>

#define STACK_SIZE 64

stack *stack_create() {
  stack *s = malloc(sizeof(stack));
  s->size = STACK_SIZE;
  s->pointer = 0;
  s->arr = malloc(STACK_SIZE * sizeof(uint64_t));
  return s;
}

void stack_push(stack *s, uint64_t val) {
  if (s->pointer >= s->size) {
    s->arr = realloc(s->arr, s->size * 2);
  }
  s->arr[s->pointer] = val;
  ++s->pointer;
}

uint64_t stack_pop(stack *s) {
  if (s->pointer == 0) {
    return INT64_MAX;
  }
  --s->pointer;
  return s->arr[s->pointer];
}

void stack_delete(stack *s) {
  free(s->arr);
  free(s);
}
