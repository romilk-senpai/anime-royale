#include "gameobject.h"
#include <stdint.h>
#include <stdlib.h>

GameObject *go_create(uint32_t instance_id, void *binding, update_go update,
                   render_go render) {
  GameObject *go = malloc(sizeof(GameObject));
  *go = (GameObject){.instance_id = instance_id,
                     .binding = binding,
                     .position = vector2_zero(),
                     .angle = 0.0,
                     .update = update,
                     .render = render};
  return go;
}
