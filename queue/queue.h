#include <stdint.h>

#ifndef queue_h
typedef struct QueueElem {
  uint64_t value;
  struct QueueElem *front;
  struct QueueElem *back;
} _queue_elem;

typedef struct Queue {
  _queue_elem *back;
  _queue_elem *front;
  uint64_t size;
} queue;

queue *queue_create();
void enqueue(queue *queue, uint64_t elem);
uint64_t dequeue(queue *queue);
uint64_t queue_size(queue *queue);
void queue_print(queue *queue);
void queue_free(queue *queue);
#endif
