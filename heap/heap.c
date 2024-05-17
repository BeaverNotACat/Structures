#include "heap.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

static inline uint64_t _arrheapp(uint64_t n) { return (n - 1) / 2; }
static inline uint64_t _arrheaplc(uint64_t n) { return 2 * n + 1; }
static inline uint64_t _arrheaprc(uint64_t n) { return 2 * n + 2; }

arrheap _empty_arrheap() {
  return (arrheap){.size = 0, .used = 0, .arr = malloc(sizeof(uint64_t) * 0)};
}

void _sift_up(arrheap *heap, uint64_t index) {
  while (index != 0 &&
         heap->cmp(heap->arr[index], heap->arr[_arrheapp(index)])) {
    register uint64_t t = heap->arr[index];
    heap->arr[index] = heap->arr[_arrheapp(index)];
    heap->arr[_arrheapp(index)] = t;

    index = _arrheapp(index);
  }
}

void _sift_down(arrheap *heap, uint64_t index) {
  uint64_t heaviest = index;

  if (_arrheaplc(index) < heap->used &&
      !heap->cmp(heap->arr[index], heap->arr[_arrheaplc(index)])) {
    heaviest = _arrheaplc(index);
  }
  if (_arrheaprc(index) < heap->used &&
      !heap->cmp(heap->arr[index], heap->arr[_arrheaprc(index)])) {
    heaviest = _arrheaprc(index);
  }

  if (heaviest != index) {
 register uint64_t t = heap->arr[index];
    heap->arr[index] = heap->arr[heaviest];
    heap->arr[heaviest] = t;
    _sift_down(heap, heaviest);
  }
}

arrheap heapify(uint64_t *arr, uint64_t usize,
                _Bool (*cmp)(uint64_t a, uint64_t b)) {
  arrheap heap = _empty_arrheap();

  heap.arr = realloc(heap.arr, sizeof(uint64_t) * usize);
  memcpy(heap.arr, arr, sizeof(uint64_t) * usize);
  heap.used = usize;
  heap.size = usize;
  heap.cmp = cmp;

  for (int i = 1; i < usize; ++i) {
    _sift_up(&heap, i);
  }
  return heap;
}

uint64_t arrheap_get_root(arrheap *heap) { return heap->arr[0]; }

uint64_t arrheap_pop_root(arrheap *heap) {
  if (!heap->used)
    return INT64_MAX;
  uint64_t root = heap->arr[0];

  --heap->used;
  heap->arr[0] = heap->arr[heap->used];
  _sift_down(heap, 0);
  return root;
}

void arrheap_push(arrheap *heap, uint64_t add) {
  if (heap->size == heap->used) {
    heap->arr = realloc(heap->arr, sizeof(heap->arr) * 2);
    heap->size *= 2;
  }

  heap->arr[heap->used] = add;
  _sift_up(heap, heap->used);
  ++heap->used;
}

void heapsort(uint64_t *arr, uint64_t usize,
              _Bool (*cmp)(uint64_t a, uint64_t b)) {
  arrheap heap = heapify(arr, usize, cmp);
  for (uint64_t i = 0; i < usize; ++i) {
    arr[i] = arrheap_pop_root(&heap);
  }
  free(heap.arr);
}

void arrheap_del(arrheap *heap) {
  if (heap->size) {
    free(heap->arr);
  }
  free(heap);
}
