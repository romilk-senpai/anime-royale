#include "go_min_heap.h"
#include <stdlib.h>

const size_t MIN_HEAP_INITIAL_CAPACITY = 10;

static int get_parent(int i) { return (i - 1) / 2; }
static int getLeftChild(int i) { return 2 * i + 1; }
static int getRightChild(int i) { return 2 * i + 2; }

min_heap *min_heap_new() { return min_heap_new_cap(MIN_HEAP_INITIAL_CAPACITY); }

min_heap *min_heap_new_cap(size_t capacity) {
  min_heap *heap = malloc(sizeof(min_heap));
  *heap = (min_heap){vector_create_cap(GameObject *, capacity)};
  return heap;
}

void min_heap_insert(min_heap *heap, GameObject *go) {
  vector_add(heap->v, go);
  int i = heap->v->size - 1;
  while (i != 0 && vector_get(heap->v, GameObject *, get_parent(i))->z_index >
                       vector_get(heap->v, GameObject *, i)->z_index) {
    GameObject *temp = vector_get(heap->v, GameObject *, i);
    ((GameObject **)heap->v->data)[i] =
        vector_get(heap->v, GameObject *, get_parent(i));
    ((GameObject **)heap->v->data)[get_parent(i)] = temp;
    i = get_parent(i);
  }
}

GameObject *min_heap_remove_min(min_heap *heap) {
  if (heap->v->size == 0) {
    return NULL;
  }

  GameObject *root = vector_get(heap->v, GameObject *, 0);
  GameObject *last = vector_get(heap->v, GameObject *, heap->v->size - 1);
  ((void **)heap->v->data)[0] = last;
  vector_remove_at(heap->v, heap->v->size - 1);

  int i = 0;
  while (1) {
    int left = getLeftChild(i);
    int right = getRightChild(i);
    int smallest = i;

    if (left < heap->v->size &&
        vector_get(heap->v, GameObject *, left)->z_index <
            vector_get(heap->v, GameObject *, smallest)->z_index) {
      smallest = left;
    }
    if (right < heap->v->size &&
        vector_get(heap->v, GameObject *, right)->z_index <
            vector_get(heap->v, GameObject *, smallest)->z_index) {
      smallest = right;
    }
    if (smallest == i) {
      break;
    }

    GameObject *temp = vector_get(heap->v, GameObject *, i);
    ((void **)heap->v->data)[i] = vector_get(heap->v, GameObject *, smallest);
    ((void **)heap->v->data)[smallest] = temp;
    i = smallest;
  }

  return root;
}

void min_heap_free(min_heap *min_heap) {
  vector_free(min_heap->v);
  free(min_heap);
}
