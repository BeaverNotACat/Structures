#include "queue.h"
#include "stdio.h"

int main() {
  queue *q = queue_create();
  for (int i = 0; i < 5; enqueue(q, ++i));
  queue_print(q);
  
  printf("%ld\n", queue_size(q));
  for (int i = 0; i < 5; ++i) {
    printf("%ld ", dequeue(q));
  }
  printf("\n");
  return 0;
}
