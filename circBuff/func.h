#ifndef FUNC_H_
#define FUNC_H_
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE !0
#define FALSE 0
#define NUM_ELEM_RING_BUFF 16
#define MASK_RING_BUFF 0x0F

typedef struct {
  uint32_t head, tail;
  uint32_t data[NUM_ELEM_RING_BUFF];
} ring_buffer_t;

void *ring_buffer_init(void);
void ring_buffer_destroy(void *);
int push(void *, uint32_t);
int pop(void *, uint32_t *);

#endif  // FUNC_H