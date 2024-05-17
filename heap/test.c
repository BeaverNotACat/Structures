#include "heap.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

_Bool cmp(uint64_t a, uint64_t b) { return a > b; }

int main() {
  uint64_t a[5] = {1, 2, 3, 4, 5};
  arrheap heap = heapify(a, 5, cmp);
  printf("%d\n", arrheap_pop_root(&heap));
  printf("%d\n", arrheap_pop_root(&heap));
  printf("%d\n", arrheap_pop_root(&heap));
  printf("%d\n", arrheap_pop_root(&heap));
  printf("%d\n", arrheap_pop_root(&heap));

  arrheap_push(&heap, 10);
  arrheap_push(&heap, 40);
  arrheap_push(&heap, 30);
  arrheap_push(&heap, 20);
  printf("max: %d\n", arrheap_get_root(&heap));
  printf("%d\n", arrheap_pop_root(&heap));
  printf("%d\n", arrheap_pop_root(&heap));
  printf("%d\n", arrheap_pop_root(&heap));
  printf("%d\n", arrheap_pop_root(&heap));
  printf("%d\n", arrheap_pop_root(&heap));

  uint64_t b[5] = {1, 2, 3, 4, 5};
  heapsort(b, 5, cmp);
  for (int i = 0; i < 5; ++i) {
    printf("%d, ", b[i]);
  }
  printf("\n");
}
