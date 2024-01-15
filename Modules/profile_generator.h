#ifndef PROFILE_GEN
#define PROFILE_GEN

#include <stdbool.h>
#include <math.h>
#include <string.h>

#define VEC_SIZE 3

typedef struct {
    float t_s;    // Sample time [s]
    float a_max;  // Maximum acceleration [m/s^2]
    float j_max;  // Maximum jerk [m/s^3]
} params_t;

void profile_generator(
    float traj[VEC_SIZE],
    float debug[VEC_SIZE],
    const float vec_in[VEC_SIZE],
    const bool override,
    const params_t *params
);

void profile_generator_refac(
    float traj[VEC_SIZE],
    float debug[VEC_SIZE],
    const float vec_in[VEC_SIZE],
    const bool override,
    const params_t *params
);

#endif