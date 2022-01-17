#ifndef _FIFO_H_
#define _FIFO_H_

#include <ctype.h>
#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node {
  int data;
  struct node *next;
} node_t;

typedef struct fifo {
  node_t *first, *last;
} fifo_t;

/**
 * @brief init a fifo list structure with first and last nodes NULL
 *
 * @return void*
 */
void *init_fifo(void);

/**
 * @brief free the memory allocated by an fifo list deleting all items
 *
 * @param fifo pointer to the structure of the list
 */
void free_fifo(void *fifo);

/**
 * @brief print the elements in order first to last of fifo
 *
 * @param fifo pointer to the structure of the list
 */
void print_fifo(void *fifo);

/**
 * @brief print the elements in inverse order last to first of fifo using
 * recursion
 *
 * @param fifo pointer to the structure of the list
 */
void print_fifo_reverse(void *fifo);

/**
 * @brief push an element at the end of the list creating a new node structure
 *
 * @param fifo pointer to the structure of the list
 * @param data element to push in the list
 */
void push_fifo(void *fifo, int data);

/**
 * @brief pop an element of the start of the list and removes the first node
 *
 * @param fifo pointer to the structure of the list
 * @param data pointer to the memory where the pop element will be stored if
 * exists
 * @return int return code 0 if success, bad request code i.o.c.
 */
int pop_fifo(void *fifo, int *data);

// for function pointers ----------------------------
void clean_data_of_fifo_node(node_t *n);
void print_data_of_fifo_node(node_t *n);
void pow2_data_of_fifo_node(node_t *n);
void increment_data_of_fifo_node(node_t *n);
void decrement_data_of_fifo_node(node_t *n);
void abs_data_of_fifo_node(node_t *n);
// --------------------------------------------------

/**
 * @brief itertive function that applicates a modification on all the nodes
 * given by a function
 *
 * @param fifo pointer to the structure of the list
 * @param fp pointer to the modifier function
 */
void iterate_fifo_nodes(void *fifo, void (*fp)(node_t *));

#endif  // _FIFO_H_
