#pragma once
#include "MemoryObj.h"

typedef struct Node {

  MemoryObj data;
  struct Node *next;

} Node;

typedef struct LinkedList {

  int length;
  Node *head;

  Node *tail;

} LinkedList;

void printList(const LinkedList *list);
void clearList(LinkedList *list);
void addNode(LinkedList *list, MemoryObj *memObj);
void findAndDelete(LinkedList *list, void *ptr);
int findIndex(const LinkedList *list, void *ptr);
void deleteFront(LinkedList *list, void *ptr);
void deleteBack(LinkedList *list, void *ptr);
Node *getElementAtIndex(LinkedList *list, int index);
