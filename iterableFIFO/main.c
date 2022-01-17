/**
 * @file main.c
 * @author Daniel Vangelov (dvangelov@mm-sol.com)
 * @brief Test fifo functions and getopt()
 * @version 0.1
 * @date 2022-01-14
 *
 * @copyright Copyright (c) 2022
 * http://www.gnu.org/software/libc/manual/html_node/Using-Getopt.html
 * USE: argv[0] [-acdeip]
 */
#include <unistd.h>
#include "fifo.h"

int main(int argc, char **argv) {
  int i, data, c, index;

  fifo_t *myfifo = (fifo_t *)init_fifo();
  print_fifo((void *)myfifo);
  if (pop_fifo((void *)myfifo, &data) == 0) printf("pop data: %d\n", data);
  for (i = 0; i < 10; i++) push_fifo((void *)myfifo, rand());
  print_fifo((void *)myfifo);
  print_fifo_reverse((void *)myfifo);
  if (pop_fifo((void *)myfifo, &data) == 0) printf("pop data: %d\n", data);
  print_fifo((void *)myfifo);
  push_fifo((void *)myfifo, rand());
  iterate_fifo_nodes(myfifo, clean_data_of_fifo_node);
  print_fifo((void *)myfifo);
  iterate_fifo_nodes(myfifo, decrement_data_of_fifo_node);
  print_fifo((void *)myfifo);
  iterate_fifo_nodes(myfifo, abs_data_of_fifo_node);
  print_fifo((void *)myfifo);
  iterate_fifo_nodes(myfifo, print_data_of_fifo_node);
  printf("\n\nGetopt() test in order of passed arguments:\n");

  //   c : clean_data_of_fifo_node();
  //   p : print_data_of_fifo_node();
  //   e : pow2_data_of_fifo_node();
  //   i : increment_data_of_fifo_node();
  //   d : decrement_data_of_fifo_node();
  //   a : abs_data_of_fifo_node();

  // opterr = 0;  // getopt flag
  while ((c = getopt(argc, argv, "pceida")) != -1) {
    switch (c) {
      case 'p':
        iterate_fifo_nodes(myfifo, print_data_of_fifo_node);
        putchar('\n');
        break;
      case 'c':
        iterate_fifo_nodes(myfifo, clean_data_of_fifo_node);
        print_fifo((void *)myfifo);
        break;
      case 'e':
        iterate_fifo_nodes(myfifo, pow2_data_of_fifo_node);
        print_fifo((void *)myfifo);
        break;
      case 'i':
        iterate_fifo_nodes(myfifo, increment_data_of_fifo_node);
        print_fifo((void *)myfifo);
        break;
      case 'd':
        iterate_fifo_nodes(myfifo, decrement_data_of_fifo_node);
        print_fifo((void *)myfifo);
        break;
      case 'a':
        iterate_fifo_nodes(myfifo, abs_data_of_fifo_node);
        print_fifo((void *)myfifo);
        break;
      case '?':
        if (isprint(optopt)) {
          fprintf(stderr, "Unknown option '-%c'.\n", optopt);
        } else {
          fprintf(stderr, "Unknown option character '\\x%x'.\n", optopt);
        }
      default:
        abort();
    }
  }

  free_fifo((void *)myfifo);
  return EXIT_SUCCESS;
}
