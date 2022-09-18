#include "memoryManager.h"
#include "LinkedList.h"
#include "MemoryObj.h"
#include "memory.h"

LinkedList *initializeMemory() {

  LinkedList *memory = (LinkedList *)calloc(1, sizeof(LinkedList));

  memory->length = 0;
  return memory;
}

void *xalloc(size_t size, LinkedList *memory, char const *msg, const int line,
             char const *file) {

  MemoryObj *memobj = (MemoryObj *)calloc(1, sizeof(MemoryObj));

  void *ptr = malloc(size);

  char *functionName = strdup(msg);
  char *fileName = strdup(file);
  setMemoryObj(memobj, ptr, line, functionName, size, fileName);

  addNode(memory, memobj);
  return ptr;
}
void xfree(void *ptr, LinkedList *memory) { findAndDelete(memory, ptr); }
