#pragma once
#include "LinkedList.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
void *xalloc(size_t size, LinkedList *memory, char const *msg, const int line);
void xfree(void *ptr, LinkedList *memory);
LinkedList *initializeMemory();
#define xalloc2(x, y) xalloc((x), (y), __FUNCTION__, __LINE__)
