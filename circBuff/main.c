#include "func.h"

int main(void) {
  int i;
  uint32_t data;
  ring_buffer_t *myrb = (ring_buffer_t *)ring_buffer_init();
  printf("Pop %d with return code %d. Head position %d and tail position %d.\n",
         i, pop((void *)myrb, &data), myrb->head, myrb->tail);
  for (i = 0; i < 20; i++) {
    printf(
        "Push %d with return code %d. Head position %d and tail position %d.\n",
        i, push((void *)myrb, i), myrb->head, myrb->tail);
  }
  printf("Pop with return code %d. Head position %d and tail position %d.\n",
         pop((void *)myrb, &data), myrb->head, myrb->tail);
  printf("Pop with return code %d. Head position %d and tail position %d.\n",
         pop((void *)myrb, &data), myrb->head, myrb->tail);
  printf("Push with return code %d. Head position %d and tail position %d.\n",
         push((void *)myrb, i), myrb->head, myrb->tail);
  printf("Pop with return code %d. Head position %d and tail position %d.\n",
         pop((void *)myrb, &data), myrb->head, myrb->tail);
  printf("Push with return code %d. Head position %d and tail position %d.\n",
         push((void *)myrb, i), myrb->head, myrb->tail);
  for (i = 0; i < 20; i++) {
    printf(
        "Pop %d with return code %d. Head position %d and tail position %d.\n",
        i, pop((void *)myrb, &data), myrb->head, myrb->tail);
  }
  ring_buffer_destroy(myrb); // myrb still save a number (pointer to freed memory. Solution myrb == NULL)
  return EXIT_SUCCESS;
}