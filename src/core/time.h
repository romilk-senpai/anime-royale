#ifndef TIME_H
#define TIME_H

typedef struct {
  float time;
  float last_time;
  float delta_time;
} Time;

Time *time_new();

#endif