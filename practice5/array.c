#include <stdio.h>
#include <stdlib.h>
#include "array.h"


void initArray(Array *a) {
  a->array = malloc(10 * sizeof(int));
  a->used = 0;
  a->size = 10;
}

void pushArray(Array *a, int element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->array = realloc(a->array, a->size * sizeof(int));
  }
  a->array[a->used++] = element;
}

void freeArray(Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}
