#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "LinkedList.h"

int main() {
  list_t list=make_list();
  if (!list) {
    printf("ERROR ALLOCATING TREE\n");
    return 1;
  }
  int quit = 0;
  size_t line_cap = 0;
  char * input = NULL;
  while (!quit) {
    printf("? ");
    int num_chars = getline( & input, & line_cap, stdin);
    if (num_chars < 0) {
      quit = 1;
    } else if (num_chars < 2) {
      printf("INVALID INPUT\n");
    } else if (input[0] == 'a'){
      if (num_chars < 4 || input[1] != ' ') {
        printf("INVALID INPUT\n");
      } else {
        size_t len = strlen(input);
        char * string = malloc(len - 2);
        input[len - 1] = 0;
        if (string) {
          strcpy(string, input + 2);
          list_add(list, string);
        }
      }
    } else if (input[0] == 'l') {
      iter_t iter = make_iterator(tree);
      if (iter) {
        char * string;
        while ((string = iter_next(iter))) {
          printf("%s\n", string);
        }
        destroy_iterator(iter);
      }
    } else if (input[0] == 'q') {
      quit = 1;
    } else {
      printf("INVALID INPUT\n");
    }
  }
  if (input) {
    free(input);
  }
  iter_t iter = make_iterator(tree);
  if (iter) {
    void * string;
    while ((string = iter_next(iter))) {
      free(string);
    }
    destroy_iterator(iter);
  }
  destroy_tree(tree);
  return 0;
}
