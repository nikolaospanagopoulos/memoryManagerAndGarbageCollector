#include "memoryManager.h"
#include "LinkedList.h"
#include "MemoryObj.h"
#include "memory.h"

LinkedList myList;

void *xalloc(size_t size, char const *msg, const int line) {

  MemoryObj *memobj = (MemoryObj *)malloc(sizeof(MemoryObj));

  void *ptr = malloc(size);

  char *functionName = strdup(msg);
  setMemoryObj(memobj, ptr, line, functionName, size);

  addNode(&myList, memobj);
  return ptr;
}
void xfree(void *ptr) { findAndDelete(&myList, ptr); }

int main() {

  initializeMemory(&myList);

  int *arr = (int *)xalloc2(4 * sizeof(int));

  int *arr2 = (int *)xalloc2(4 * sizeof(int));
  int *arr3 = (int *)xalloc2(4 * sizeof(int));

  arr[0] = 1;
  arr[1] = 2;
  arr[2] = 3;
  arr[3] = 4;

  for (size_t i = 0; i < 4; i++) {
    printf("%d", arr[i]);
  }
  xfree(arr);
  xfree(arr2);
  xfree(arr3);

  clearList(&myList);

  return 0;
}
