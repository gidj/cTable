#include <stdbool.h>
#include <stddef.h>

#ifndef LIST_H_
#define LIST_H_

typedef struct List *List;

extern List list_new(int elementSize);
extern void list_destroy(List *list);
extern size_t list_length(List list);

extern void* list_append(List list, void *element);
extern void* list_prepend(List list, void *element);

extern void* list_pop(List list);
extern void* list_peek(List list);
extern void* list_head(List list);
extern void* list_tail(List list);
extern void* list_item(List list, size_t index);
#endif
