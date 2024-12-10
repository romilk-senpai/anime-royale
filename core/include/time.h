#ifndef TIME_H
#define TIME_H

typedef struct {
  float time;
  float last_time;
  float delta_time;
} Time;

void time_handle(Time *self);

#endif
