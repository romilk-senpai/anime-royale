#ifndef COLLISION_H
#define COLLISION_H

#include "game.h"
#include "map.h"
#include "vector2.h"

enum ColliderType { CIRCLE, RECT };

typedef struct {
  Vector2 pos;
  float radius;
} CircleCollider;

typedef struct {
  Vector2 pos;
  Vector2 size;
} RectCollider;

typedef struct {
  void *collider;
  enum ColliderType col_type;
} CollisionInfo;

typedef void (*on_collision)(GameState *state, CollisionInfo *collision_info);

typedef struct {
  void *collider;
  enum ColliderType col_type;
  on_collision on_collision;
} CollisionListener;

void process_collision(CollisionListener *listener, CollisionInfo info);

typedef struct {
  hash_map *circle_st_cols;
  hash_map *rect_st_cols;
  hash_map *listeners;
} Collision;

void collision_add_rect_col(Collision *collision, RectCollider *col);
void collision_remove_rect_col(Collision *collision, RectCollider *col);
void collision_add_circle_col(Collision *collision, CircleCollider *col);
void collision_remove_circle_col(Collision *collision, CircleCollider *col);
void collision_add_listener(Collision *collision,
                            CollisionListener *collision_listener);
void collision_remove_listener(Collision *collision,
                               CollisionListener *collision_listener);
void collision_update(Collision *collision, GameState *state);
static int cmp_rect_rect(RectCollider *r1, RectCollider *r2);
static int cmp_rect_circle(RectCollider *r, CircleCollider *c);
static int cmp_circle_circle(CircleCollider *c1, CircleCollider *c2);

#endif
