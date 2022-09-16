#pragma once
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
void *xalloc(size_t size, char const *msg, const int line);
void xfree(void *ptr);
#define xalloc2(x) xalloc((x), __FUNCTION__, __LINE__)
