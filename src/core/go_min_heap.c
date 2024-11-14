#include "go_min_heap.h"
#include "gameobject.h"
#include "vector.h"
#include <stdlib.h>

const size_t MIN_HEAP_INITIAL_CAPACITY = 10;

int getParent(int i) { return (i - 1) / 2; }
int getLeftChild(int i) { return 2 * i + 1; }
int getRightChild(int i) { return 2 * i + 2; }

min_heap *min_heap_new() { return min_heap_new_cap(MIN_HEAP_INITIAL_CAPACITY); }

min_heap *min_heap_new_cap(size_t capacity) {
  min_heap *heap = malloc(sizeof(min_heap));
  *heap = (min_heap){vector_create_cap(GameObject *, capacity)};
  return heap;
}

void min_heap_insert(min_heap *min_heap, GameObject *go) {
  vector_add(min_heap->v, go);
  int i = min_heap->v->size - 1;
  while (i != 0 &&
         vector_get(min_heap->v, GameObject *, getParent(i))->z_index >
             vector_get(min_heap->v, GameObject *, i)->z_index) {
    GameObject *temp = vector_get(min_heap->v, GameObject *, i);
    ((void **)min_heap->v->data)[i] =
        vector_get(min_heap->v, GameObject *, getParent(i));
    ((void **)min_heap->v->data)[getParent(i)] = temp;
    i = getParent(i);
  }
}

void min_heap_free(min_heap *min_heap) {
  vector_free(min_heap->v);
  free(min_heap);
}
