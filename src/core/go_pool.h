#ifndef GO_POOL_H
#define GO_POOL_H

#include "gameobject.h"
#include <map.h>

typedef struct {
  hash_map *go_map;
  uint32_t next_id;
} GOPool;

GOPool *go_pool_new();
uint32_t go_pool_new_id(GOPool *go_pool);
void go_pool_bind(GOPool *go_pool, GameObject *go);
void go_pool_unbind(GOPool *go_pool, GameObject *go);

#endif
