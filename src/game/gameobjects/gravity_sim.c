#include "gravity_sim.h"
#include "celestial_body.h"
#include "go_pool.h"
#include "level_layout.h"
#include "vector.h"
#include "vector2.h"
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_stdinc.h>
#include <stdlib.h>

GravitySim *gravity_sim_new(GameState *state, LevelLayout *layout) {
  GravitySim *gravity_sim = malloc(sizeof(GravitySim));
  GameObject *go =
      go_create(go_pool_new_id(state->go_pool), gravity_sim, update, render);
  gravity_sim->go = go;
  gravity_sim->sim_bodies =
      vector_create_cap(CelestialBody *, layout->num_planets);
  for (size_t i = 0; i < layout->num_planets; i++) {
    vector_add(gravity_sim->sim_bodies, layout->planets[i]->celestial_body);
  }
  vector_add(gravity_sim->sim_bodies, layout->star->celestial_body);
  go_pool_bind(state->go_pool, go);
  return gravity_sim;
}

static void update(GameState *state, void *context) {
  GravitySim *sim = (GravitySim *)context;
  CelestialBody **bodies = (CelestialBody **)sim->sim_bodies->data;
  for (size_t i = 0; i < sim->sim_bodies->size; i++) {
    bodies[i]->acceleration = vector2_zero();
    for (size_t j = 0; j < sim->sim_bodies->size; j++) {
      if (i != j) {
        Vector2 dv = {bodies[j]->position->x - bodies[i]->position->x,
                      bodies[j]->position->y - bodies[i]->position->y};
        float distance = vector2_magnitude(dv);
        float force = 0.1 * bodies[i]->mass * bodies[j]->mass /
                      (distance * distance + 1e-5);
        float angle = atan2(dv.y, dv.x);
        bodies[i]->acceleration.x += force * cos(angle) / bodies[i]->mass;
        bodies[i]->acceleration.y += force * sin(angle) / bodies[i]->mass;
      }
    }
  }

  for (size_t i = 0; i < sim->sim_bodies->size; i++) {
    bodies[i]->velocity.x +=
        bodies[i]->acceleration.x * state->time->delta_time * 100;
    bodies[i]->velocity.y +=
        bodies[i]->acceleration.y * state->time->delta_time * 100;
    bodies[i]->position->x +=
        bodies[i]->velocity.x * state->time->delta_time * 100;
    bodies[i]->position->y +=
        bodies[i]->velocity.y * state->time->delta_time * 100;
  }
}

static void render(GameState *state, void *context) {}
