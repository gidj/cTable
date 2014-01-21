#include "list.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef struct Node *Node;

struct Node {
  void *data;
  Node next;
};

struct List {
  int length;
  int elementSize;
  Node head;
  Node tail;
};

List list_new(int elementSize)
{
  assert(elementSize > 0);
  List n = malloc(sizeof(*n));

  n->length = 0;
  n->elementSize = elementSize;
  n->head = n->tail = NULL;

  return n;
}

void list_destroy(List *list)
{
  assert(list && *list);
  Node current;

  while((*list)->head) {
    current = (*list)->head;
    (*list)->head = current->next;
    free(current->data);
    free(current);
  }

  free(*list);
  *list = NULL;
}

size_t list_length(List list)
{
  return list->length;
}

void* list_append(List list, void *element)
{
  assert(list);
  assert(element);

  Node new_node = malloc(sizeof(*new_node));
  new_node->data = malloc(list->elementSize);
  memcpy(new_node->data, element, list->elementSize);

  new_node->next = NULL;

  if (list->length == 0)
  {
    list->head = list->tail = new_node;
  } 
  else 
  {
    list->tail->next = new_node;
    list->tail = new_node;
  }
    
  list->length++;
  return new_node->data;
}

void* list_prepend(List list, void *element)
{
  assert(list);
  assert(element);

  Node new_node = malloc(sizeof(*new_node));
  new_node->data = malloc(list->elementSize);
  memcpy(new_node->data, element, list->elementSize);
  
  new_node->next = list->head;
  list->head = new_node;

  if (!list->tail) { list->tail = new_node; }

  list->length++;
  return new_node->data;
}

void* list_pop(List list)
{
  void* data;
  memcpy(data, list->head->data, list->elementSize);
  
  Node tmp = list->head;
  list->head = list->head->next;

  free(tmp->data);
  free(tmp);

  list->length--;
  return data;
}

void* list_peek(List list)
{
  return list->head->data;
}

void* list_item(List list, size_t index)
{
  if (index >= list->length)
  {
    printf("Given index is greater than the number of list items.\n");
    return NULL;
  }
  else
  {
    Node ptr = list->head;
    for (int i = 0; i != index; ++i)
    {
      ptr = ptr->next;
    }
    return ptr->data;
  }
}
