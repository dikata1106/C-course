#include "fifo.h"

void *init_fifo(void) {
  fifo_t *fifo = (fifo_t *)malloc(sizeof(fifo_t));
  fifo->first = fifo->last = NULL;
  return (void *)fifo;
}

void free_fifo(void *fifo) {
  fifo_t *f = (fifo_t *)fifo;
  node_t *current = f->first;
  while (current) {
    f->first = current->next;
    free(current);
    current = f->first;
  }
}

node_t *create_node(int data) {
  node_t *node = (node_t *)malloc(sizeof(node_t));
  // assert node != NULL
  node->data = data;
  node->next = NULL;
  return node;
}

void print_fifo(void *fifo) {
  fifo_t *f = (fifo_t *)fifo;
  node_t *current = f->first;
  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }
  putchar('\n');
}

void print_listR_aux(node_t *list) {
  if (!list) {
    return;
  }
  print_listR_aux(list->next);
  printf("%d ", list->data);
  // print_listR_aux(list->next); // for recursive non reverse
}

void print_fifo_reverse(void *fifo) {  // recursive and reverse
  fifo_t *f = (fifo_t *)fifo;
  node_t *current = f->first;
  if (!current) {
    return;
  }
  print_listR_aux(current);
  putchar('\n');
}

void push_fifo(void *fifo, int data) {
  fifo_t *f = (fifo_t *)fifo;
  node_t *n = create_node(data);
  // (f->last) ? (f->last->next = n) : (f->first = n);
  if (f->last) {
    f->last->next = n;
  } else {
    f->first = n;
  }
  f->last = n;
}

int pop_fifo(void *fifo, int *data) {
  int rc = -EBADRQC;
  fifo_t *f = (fifo_t *)fifo;
  node_t *current = f->first;
  if (current) {
    *data = current->data;
    f->first = current->next;
    free(current);
    rc = 0;
  }
  return rc;
}

void clean_data_of_fifo_node(node_t *n) { n->data = 0; }

void print_data_of_fifo_node(node_t *n) { printf(" %d ", n->data); }

void pow2_data_of_fifo_node(node_t *n) { n->data *= n->data; }

void increment_data_of_fifo_node(node_t *n) { n->data++; }

void decrement_data_of_fifo_node(node_t *n) { n->data--; }

void abs_data_of_fifo_node(node_t *n) { n->data *= n->data; }

void iterate_fifo_nodes(void *fifo, void (*fp)(node_t *)) {
  fifo_t *f = (fifo_t *)fifo;
  node_t *current = f->first;
  while (current) {
    fp(current);
    current = current->next;
  }
}
