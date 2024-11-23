#include "collision.h"
#include "hash.h"
#include "map.h"
#include <stdlib.h>

void process_collision(CollisionListener *listener, CollisionInfo info) {

}

Collision *collision_new(GameState *state) {
  Collision *collision = malloc(sizeof(Collision));
  collision->listeners = hash_map_create(fnv1a_hash);
  collision->circle_st_cols = hash_map_create(fnv1a_hash);
  collision->rect_st_cols = hash_map_create(fnv1a_hash);
  return collision;
}

void collision_add_rect_col(Collision *collision, RectCollider *col) {
  hash_map_set(collision->rect_st_cols, col, col);
}

void collision_remove_rect_col(Collision *collision, RectCollider *col) {
  hash_map_delete(collision->rect_st_cols, col);
}

void collision_add_circle_col(Collision *collision, CircleCollider *col) {
  hash_map_set(collision->circle_st_cols, col, col);
}

void collision_remove_circle_col(Collision *collision, CircleCollider *col) {
  hash_map_delete(collision->circle_st_cols, col);
}

void collision_add_listener(Collision *collision,
                            CollisionListener *collision_listener) {
  hash_map_set(collision->listeners, collision_listener, collision_listener);
}

void collision_remove_listener(Collision *collision,
                               CollisionListener *collision_listener) {
  hash_map_delete(collision->listeners, collision_listener);
}

static void cmp_rect_rect_for_each(key_value_pair *kvp, void *context) {
  RectCollider *other = (RectCollider *)kvp->value;
  CollisionListener *listener = (CollisionListener *)context;
  RectCollider *l_col = (RectCollider *)listener->collider;
  if (cmp_rect_rect(l_col, other)) {
    CollisionInfo info = {l_col, RECT};
    process_collision(listener, info);
  }
}

static void cmp_circle_rect_for_each(key_value_pair *kvp, void *context) {
  CircleCollider *other = (CircleCollider *)kvp->value;
  CollisionListener *listener = (CollisionListener *)context;
  RectCollider *l_col = (RectCollider *)listener->collider;
  if (cmp_rect_circle(l_col, other)) {
    CollisionInfo info = {l_col, RECT};
    process_collision(listener, info);
  }
}

static void cmp_rect_circle_for_each(key_value_pair *kvp, void *context) {
  RectCollider *other = (RectCollider *)kvp->value;
  CollisionListener *listener = (CollisionListener *)context;
  CircleCollider *l_col = (CircleCollider *)listener->collider;
  if (cmp_rect_circle(other, l_col)) {
    CollisionInfo info = {l_col, RECT};
    process_collision(listener, info);
  }
}

static void cmp_circle_circle_for_each(key_value_pair *kvp, void *context) {
  CircleCollider *other = (CircleCollider *)kvp->value;
  CollisionListener *listener = (CollisionListener *)context;
  CircleCollider *l_col = (CircleCollider *)listener->collider;
  if (cmp_circle_circle(l_col, other)) {
    CollisionInfo info = {l_col, RECT};
    process_collision(listener, info);
  }
}

static void listeners_for_each(key_value_pair *kvp, void *context) {
  Collision *collision = (Collision *)context;
  CollisionListener *listener = (CollisionListener *)kvp->value;

  if (listener->col_type == RECT) {
    hash_map_for_each(collision->rect_st_cols, cmp_rect_rect_for_each,
                      listener);
    hash_map_for_each(collision->circle_st_cols, cmp_circle_rect_for_each,
                      listener);
  } else {
    hash_map_for_each(collision->rect_st_cols, cmp_rect_circle_for_each,
                      listener);
    hash_map_for_each(collision->circle_st_cols, cmp_circle_circle_for_each,
                      listener);
  }
}

void collision_update(Collision *collision, GameState *state) {
  hash_map_for_each(collision->listeners, listeners_for_each, collision);
}

static int cmp_rect_rect(RectCollider *r1, RectCollider *r2) {
  return !(
      r1->pos.x + r1->pos.x < r2->pos.x || r2->pos.x + r2->pos.x < r1->pos.x ||
      r1->pos.y + r1->pos.y < r2->pos.y || r2->pos.y + r2->pos.y < r1->pos.y);
}

static float clamp(float value, float min, float max) {
  if (value < min)
    return min;
  if (value > max)
    return max;
  return value;
}

static int cmp_rect_circle(RectCollider *r, CircleCollider *c) {
  Vector2 nearest = {clamp(c->pos.x, r->pos.x, r->pos.x + r->size.x),
                     clamp(c->pos.y, r->pos.y, r->pos.y + r->size.y)};
  Vector2 dv = vector2_sub(c->pos, nearest);
  float distance_squared = dv.x * dv.x + dv.y * dv.y;
  return distance_squared <= (c->radius * c->radius);
}

static int cmp_circle_circle(CircleCollider *c1, CircleCollider *c2) {
  float dist = vector2_magnitude(vector2_sub(c2->pos, c1->pos));
  return dist <= (c1->radius + c2->radius);
}
