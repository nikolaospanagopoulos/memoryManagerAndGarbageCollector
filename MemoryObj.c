#include "MemoryObj.h"
#include <stdio.h>

void printMemoryData(const MemoryObj *mobj) {

  printf("details for the leaked memory: \n the pointer address is: %p, \n the "
         "bytes requested are: %zu, \n the "
         "calling function is: %s, \n the line number is: %d \n the file name "
         "is: %s \n",
         mobj->address, mobj->size, mobj->functionName, mobj->lineNumber,
         mobj->fileName);
}
void setMemoryObj(MemoryObj *mobj, void *address, int lineNumber,
                  char *functionName, size_t size, char *fileName) {

  mobj->address = address;
  mobj->lineNumber = lineNumber;
  mobj->functionName = functionName;
  mobj->fileName = fileName;
  mobj->size = size;
}
