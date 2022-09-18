#include "LinkedList.h"
#include "memory.h"
#include <stdio.h>
#include <stdlib.h>

void printList(const LinkedList *list) {
  if (list->length == 0) {
    printf("nikos");
  }
  Node *current = list->head;
  while (current) {
    printMemoryData(&current->data);
    current = current->next;
  }
}

Node *getElementAtIndex(LinkedList *list, int index) {

  int currentIndex = 0;
  Node *current = list->head;
  while (current) {

    if (currentIndex == index) {
      return current;
    }

    current = current->next;
    currentIndex++;
  }
  return NULL;
}

void addNode(LinkedList *list, MemoryObj *memObj) {

  Node *added = (Node *)calloc(1, sizeof(Node));
  added->data = *memObj;
  if (list->head == NULL) {
    list->head = list->tail = added;
  } else {
    list->tail->next = added;
    list->tail = added;
  }
  list->length += 1;
  free(memObj);
}

void clearList(LinkedList *list) {

  while (list->head != NULL && list->length > 0) {
    Node *current = list->head->next;

    printMemoryData(&list->head->data);
    free(list->head->data.functionName);
    free(list->head->data.address);
    free(list->head);
    list->head = current;
    list->length--;
  }
  free(list);
}

void findAndDelete(LinkedList *list, void *ptr) {

  int index = findIndex(list, ptr);

  printf("index is %d \n", index);

  if (index == 0) {
    deleteFront(list, ptr);
    return;
  }

  if (index == list->length - 1) {

    deleteBack(list, ptr);
    return;
  }

  Node *previous = getElementAtIndex(list, index - 1);
  Node *current = previous->next;
  previous->next = current->next;
  free(current->data.functionName);
  free(current->data.address);
  free(current);
  list->length--;
}

void deleteBack(LinkedList *list, void *ptr) {
  if (list->length == 1) {
    deleteFront(list, ptr);
    return;
  }
  Node *beforeLast = getElementAtIndex(list, list->length - 2);
  list->tail = beforeLast;
  free(beforeLast->next->data.address);
  free(beforeLast->next->data.functionName);
  free(beforeLast->next);
  list->tail->next = NULL;
  list->length--;
}
void deleteFront(LinkedList *list, void *ptr) {

  if (!list->head) {
    printf("no elements to delete \n");
    return;
  }

  Node *current = list->head;
  list->head = current->next;

  if (current->data.address == ptr) {
    free(current->data.address);
    free(current->data.functionName);
    free(current);
  }
  list->length--;
}
int findIndex(const LinkedList *list, void *ptr) {

  int currentIndex = 0;
  Node *current = list->head;
  while (current) {

    if (current->data.address == ptr) {
      printf("cur:%d , ptr: %p\n", currentIndex, current->data.address);
      return currentIndex;
    }

    current = current->next;
    currentIndex++;
  }
  return -1;
}
