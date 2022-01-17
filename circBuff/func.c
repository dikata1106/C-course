#include "func.h"

void *ring_buffer_init(void) {
  ring_buffer_t *ring_buffer = (ring_buffer_t *)malloc(sizeof(ring_buffer_t));
  ring_buffer->head = 0;
  ring_buffer->tail = 0;
  return (void *)ring_buffer;
}

void ring_buffer_destroy(void *rb) { free(rb); }

int push(void *rb, uint32_t elem) {
  int rc = 0;
  ring_buffer_t *ring_buffer = (ring_buffer_t *)rb;
  uint32_t tmp = (ring_buffer->head + 1) & MASK_RING_BUFF;
  if (tmp != ring_buffer->tail) {
    ring_buffer->data[ring_buffer->head] = elem;
    ring_buffer->head = tmp;
  } else {
    rc = -1;
  }
  return rc;
}

int pop(void *rb, uint32_t *elem) {
  int rc = 0;
  ring_buffer_t *ring_buffer = (ring_buffer_t *)rb;
  if (ring_buffer->tail != ring_buffer->head) {
    *elem = ring_buffer->data[ring_buffer->tail];
    ring_buffer->tail = (ring_buffer->tail + 1) & MASK_RING_BUFF;;
  } else {
    rc = -1;
  }
  return rc;
}