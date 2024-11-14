#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include "gameobject.h"
#include "vector.h"

typedef struct {
  vector *v;
} min_heap;

min_heap *min_heap_new();
min_heap *min_heap_new_cap(size_t capacity);
void min_heap_insert(min_heap *min_heap, GameObject *go);
void min_heap_free(min_heap *min_heap);

#endif
