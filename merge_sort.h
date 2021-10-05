#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "pilha.c"
#include <stdio.h>
#include <stdlib.h>

stack* merge_sort(stack* list, int start, int finish);
stack* merge(stack* list, int start, int half, int finish);

#endif