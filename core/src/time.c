#include "time.h"
#include <stdlib.h>

Time *time_new() {
  Time *t = malloc(sizeof(Time));
  *t = (Time){0.0, 0.0};
  return t;
}
