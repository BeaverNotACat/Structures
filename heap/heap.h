#include <stdint.h>
#include <stdbool.h>

#ifndef heap_h
typedef struct arrHeap{
  uint64_t size;
  uint64_t used;
  uint64_t *arr;
  _Bool (*cmp)(uint64_t a, uint64_t b);
} arrheap;

arrheap heapify(uint64_t *arr, uint64_t usize, _Bool (*cmp)(uint64_t a, uint64_t b));
uint64_t arrheap_get_root(arrheap *heap);
uint64_t arrheap_pop_root(arrheap *heap);
void arrheap_push(arrheap *heap, uint64_t add);
void heapsort(uint64_t *arr, uint64_t usize, _Bool (*cmp)(uint64_t a, uint64_t b));
#endif
