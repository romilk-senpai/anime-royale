#ifndef HASH_FUNCS_H
#define HASH_FUNCS_H

#include <stdint.h>

static uint32_t djb2_hash(void *val) {
  uint32_t value = *(uint32_t *)val;
  uint32_t hash = 5381;
  for (int i = 0; i < 4; i++) {
    uint8_t byte = (value >> (i * 8)) & 0xFF;
    hash = ((hash << 5) + hash) + byte;
  }
  return hash;
}

static uint32_t fnv1a_hash(void *val) {
  uint32_t value = *(uint32_t *)val;
  uint32_t hash = 2166136261u;
  for (int i = 0; i < 8; i++) {
    uint8_t byte = (value >> (i * 8)) & 0xFF;
    hash ^= byte;
    hash *= 16777619u;
  }
  return hash;
}
#endif
