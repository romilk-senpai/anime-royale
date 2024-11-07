#include "go_pool.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static uint32_t djb2(void *val) {
  int value = *(int *)val;
  uint32_t hash = 5381;
  for (int i = 0; i < 4; i++) {
    uint8_t byte = (value >> (i * 8)) & 0xFF;
    hash = ((hash << 5) + hash) + byte;
  }
  return hash;
}

GOPool *go_pool_new() {
  GOPool *go_manager = malloc(sizeof(GOPool));
  hash_map *map = hash_map_create_cap(1000, djb2);
  *go_manager = (GOPool){map, 0};
  return go_manager;
}

uint32_t go_pool_new_id(GOPool *go_pool) { return go_pool->next_id++; }

void go_pool_bind(GOPool *go_pool, GameObject *go) {
  if (hash_map_contains(go_pool->go_map, &go->instance_id) == 1) {
    printf(stderr, "pool already contains an object with id %zu", go->instance_id);
    return;
  }
  hash_map_set(go_pool->go_map, &go->instance_id, go);
}

void go_pool_unbind(GOPool *go_pool, GameObject *go) {

}
