#include "queue.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline _queue_elem *_queue_elem_create() {
  return calloc(1, sizeof(_queue_elem));
}

queue *queue_create() { return calloc(1, sizeof(queue)); }

void enqueue(queue *queue, uint64_t elem) {
  _queue_elem *new_elem = _queue_elem_create();
  new_elem->value = elem;

  if (queue->size) {
    new_elem->front = queue->back;
    queue->back->back = new_elem;
    queue->back = new_elem;
  } else {
    queue->back = new_elem;
    queue->front = new_elem;
  }
  ++queue->size;
}

uint64_t dequeue(queue *queue) {
  _queue_elem *elem = queue->front;
  uint64_t value = elem->value;

  if (queue->size > 1) {
    queue->front = elem->back;
    queue->front->front = NULL;
  } else {
    queue->front = NULL;
    queue->back = NULL;
  }
  free(elem);
  --queue->size;
  return value;
}

uint64_t queue_size(queue *queue) { return queue->size; }

void queue_print(queue *queue) {
  for (_queue_elem *elem = queue->front; elem; elem = elem->back) {
    printf("%lu ", elem->value);
  }
  printf("\n");
}

void queue_free(queue *queue) {
  _queue_elem *elem = queue->front;
  for (_queue_elem *next_elem = elem->back; elem; elem = next_elem) {
    free(elem);
  }
  free(queue);
}
