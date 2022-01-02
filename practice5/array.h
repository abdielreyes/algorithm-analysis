#include <stdio.h>
#include <stdlib.h>

#ifndef array

typedef struct {
  int *array;
  size_t used;
  size_t size;
} Array;

typedef Array* array;

void initArray(Array *a);
void pushArray(Array *,int element);
void freeArray(Array *);

#endif
