#include "LinkedList.h"
#include "memory.h"
#include <stdio.h>
#include <stdlib.h>

void initializeMemory(LinkedList *list) { memset(list, 0, sizeof(*list)); }

void printList(const LinkedList *list) {
  Node *current = list->head;
  while (current) {
    printMemoryData(&current->data);
    current = current->next;
  }
}

void addNode(LinkedList *list, MemoryObj *memObj) {

  Node *added = (Node *)malloc(sizeof(Node));
  added->data = *memObj;
  if (list->head == NULL) {
    list->head = list->tail = added;
  } else {
    list->tail->next = added;
    list->tail = added;
  }
  list->length++;
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
}

void findAndDelete(LinkedList *list, void *ptr) {
  if (list->length == 1) {
    free(list->head->data.functionName);
    free(list->head->data.address);
    free(list->head);

  } else if (list->length > 1) {
    Node *prv = list->head;
    Node *current = list->head->next;
    while (current != NULL) {

      if (current->data.address == ptr) {
        prv->next = current->next;
        free(current->data.address);
        free(current->data.functionName);
        free(current);
        break;
      }

      current = current->next;
      prv = prv->next;
    }
  }
  list->length--;
}
