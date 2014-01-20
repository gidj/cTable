#ifndef TABLE_H_
#define TABLE_H_ 

typedef struct Table *Table;

extern Table table_new(int hint, 
    int cmp(const void *x, const void *y), 
    unsigned hash(const void *key));
extern void table_free(Table t);
extern int  table_length(Table t);
extern void* table_put(Table t, const void *key, const void *value);
extern void* table_get(Table t, const void *key);
extern void* table_remove(Table t, const void *key);

#endif
