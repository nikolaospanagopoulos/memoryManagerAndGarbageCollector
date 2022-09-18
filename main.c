#include "memoryManager.h"

int main() {

  LinkedList *memory = initializeMemory();

  int *arr = (int *)xalloc2(4 * sizeof(int), memory);

  xfree(arr, memory);

  int *arr2 = (int *)xalloc2(4 * sizeof(int), memory);

  for (size_t i = 0; i < 4; i++) {
    arr[i] = i;
  }
  int *arr3 = (int *)xalloc2(4 * sizeof(int), memory);

  xfree(arr2, memory);
  xfree(arr3, memory);

  clearList(memory);

  return 0;
}
