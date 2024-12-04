#include "go_pool.h"
#include "hash.h"
#include <stdio.h>

GOPool go_pool_create() {
  hash_map *map = hash_map_create_cap(100, fnv1a_hash);
  return (GOPool){map, 0};
}

uint32_t go_pool_new_id(GOPool *go_pool) { return go_pool->next_id++; }

void go_pool_bind(GOPool *go_pool, GameObject *go) {
  if (hash_map_contains(go_pool->go_map, &go->instance_id)) {
    fprintf(stderr, "pool already contains an object with id %u: %u\n",
            go->instance_id,
            ((GameObject *)hash_map_get(go_pool->go_map, &go->instance_id))
                ->instance_id);
    return;
  }
  hash_map_set(go_pool->go_map, &go->instance_id, go);
}

void go_pool_unbind(GOPool *go_pool, GameObject *go) {
  if (!hash_map_contains(go_pool->go_map, &go->instance_id)) {
    fprintf(stderr, "pool does not contain an object with id %u: %u\n",
            go->instance_id,
            ((GameObject *)hash_map_get(go_pool->go_map, &go->instance_id))
                ->instance_id);
    return;
  }
  hash_map_delete(go_pool->go_map, &go->instance_id);
}
