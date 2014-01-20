#include "table.h"

struct Table {
  int length;
  int size;
  int (*cmp)(const void *x, const void *y);
  unsigned (*hash)(const void *key);

  struct binding {
    struct binding *link;
    const void *key;
    void *value;
  };
};
