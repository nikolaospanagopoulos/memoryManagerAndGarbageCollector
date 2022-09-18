#pragma once

#include <stddef.h>
typedef struct MemoryObj {

  void *address;
  int lineNumber;
  char *functionName;
  size_t size;
  char *fileName;

} MemoryObj;

void printMemoryData(const MemoryObj *mobj);
void setMemoryObj(MemoryObj *mobj, void *address, int lineNumber,
                  char *functionName, size_t size, char *fileName);
