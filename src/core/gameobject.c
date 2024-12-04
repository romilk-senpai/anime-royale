#include "gameobject.h"
#include <stdint.h>

GameObject go_create(uint32_t instance_id, void *binding, update_func update,
                     render_func render) {
  return (GameObject){.instance_id = instance_id,
                      .binding = binding,
                      .position = vector2_zero(),
                      .angle = 0.0,
                      .update = update,
                      .render = render,
                      .z_index = 0};
}
