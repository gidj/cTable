#include "table.h"
#include "include/array/array.h"
#include "include/list/list.h"
#include <assert.h>
#include <limits.h>
#include <stdlib.h>

int default_cmp(const void*, const void*);
unsigned default_hash(const void*);

struct binding {
  const void *key;
  void *value;
};

struct Table {
  int length;
  int num_elements;
  int (*cmp)(const void *x, const void *y);
  unsigned (*hash)(const void *key);

  Array dict;
};

Table table_new(int hint,
    int cmp(const void *x, const void *y),
    unsigned hash(const void *key))
{
  assert(hint >= 0);
  Table t;
  int i;
  int primes[] = {509, 509, 1021, 2053, 4093, 8191, 16381, 32771, 65521, INT_MAX };

  for (i = 1; primes[i] < hint; ++i)
  {
/* This empty loop simply selects the index i of the prime number that is 
 * closest to 'hint' in the array 'primes[]'. A prime number is used as the
 * size length of the array that stores the hashed items because it generally
 * spreads the hashed items out more evenly. */ 
  }

  t = malloc(sizeof(*t));
  assert(t);
  t->length = primes[i-1];
  t->num_elements = 0;
/* TODO change the default functions for default_hash and default_cmp*/ 
  t->cmp = cmp ? cmp : default_cmp;
  t->hash = hash ? hash : default_hash;
  t->dict = array_new(t->length, sizeof(List));

  return t;
}

/* The default comparison function simply tests to see whether the two given
 * pointers are equal when evaluated as integers. 
 *
 * TODO: include the Atom ADT */ 
int default_cmp(const void *x, const void *y)
{
  return *(int*) x != *(int*) y;
}

unsigned default_hash(const void *key)
{
  return (unsigned long) key >> 2;
}

