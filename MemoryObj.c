#include "MemoryObj.h"
#include <stdio.h>

void printMemoryData(const MemoryObj *mobj) {

  printf("the pointer address is: %p, \n the bytes requested are: %zu, \n the "
         "calling function is: %s, \n the line number is: %d \n",
         mobj->address, mobj->size, mobj->functionName, mobj->lineNumber);
}
void setMemoryObj(MemoryObj *mobj, void *address, int lineNumber,
                  char *functionName, size_t size) {

  mobj->address = address;
  mobj->lineNumber = lineNumber;
  mobj->functionName = functionName;
  mobj->size = size;
}
