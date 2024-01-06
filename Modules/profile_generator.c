#include "profile_generator.h"

void profile_generator(
    float traj[VEC_SIZE],
    float debug[VEC_SIZE],
    const float vec_in[VEC_SIZE],
    const bool override,
    const params_t *params
) {
    static float t = 0.0f;
    static float vec_old[VEC_SIZE] = {0.0f, 0.0f, 0.0f};
    static bool override_old = false;

    float vec_out[VEC_SIZE];

    if (override) {
        if (vec_in[0] != vec_old[0] || override > override_old) {
            memmove(vec_out, vec_in, sizeof(vec_in[0]) * VEC_SIZE);
            memmove(vec_old, vec_in, sizeof(vec_in[0]) * VEC_SIZE);
            t = 0.0f;
        }
        else {
            memmove(vec_out, vec_old, sizeof(vec_old[0]) * VEC_SIZE);
            t += params->t_s;
        }
    }
    else {
        vec_out[0] = vec_in[0];
        vec_out[1] = vec_in[0];
        vec_out[2] = vec_in[2];
        t = 0.0f;
    }
    override_old = override;

    float v_0 = vec_out[1];
    float v_target = vec_out[0];
    float v_diff = v_target - v_0;

    float a_traj, j_traj;

    if (fabsf(v_diff) <= 0.1f) {
        a_traj = 0.0f;
        j_traj = 0.0f;
    }
    else {
        a_traj = (v_diff > 0) ? params->a_max : -params->a_max;
        j_traj = (v_diff > 0) ? params->j_max : -params->j_max;
    }

    float a_diff = a_traj - vec_out[2];
    float t1 = fabsf(a_diff / params->j_max);
    float j_traj_1 = (a_diff < 0) ? -params->j_max : ((a_diff == 0) ? 0.0f : params->j_max);

    float v_1 = 0.5f * j_traj_1 * t1 * t1 + vec_out[2] * t1;
    float t3 = params->a_max / params->j_max;
    float v_3 = 0.5f * j_traj * t3 * t3;

    float t23 = (v_diff - v_1 - v_3) / a_traj;
    float t2;

    if (t23 < 0) {
        t1 = -vec_out[2] / j_traj_1 + sqrtf(vec_out[2] * vec_out[2] / (2 * j_traj_1 * j_traj_1) + v_diff / j_traj_1);
        t3 = t1 + sqrtf(vec_out[2] * vec_out[2] / (2 * j_traj_1 * j_traj_1) + v_diff / j_traj_1);
        t23 = 0.0f;

        a_traj = j_traj_1 * t1 + vec_out[2];
        t2 = t1 + t23;
    }
    else {
        t2 = t1 + t23;
        t3 = t2 + t3;
    }

    if (t < t1) {
        traj[2] = j_traj_1;                                          //j_soll
        traj[1] = j_traj_1 * t + vec_out[2];                         //a_soll
        traj[0] = 0.5f * j_traj_1 * t * t + vec_out[2] * t + v_0;    //v_soll
    }
    else if (t < t2) {
        traj[2] = 0.0f;
        traj[1] = a_traj;
        traj[0] = a_traj * (t - t1) + 0.5f * j_traj_1 * t1 * t1 + v_0 + vec_out[2] * t1;
    }
    else if (t < t3) {
        traj[2] = -j_traj;
        traj[1] = a_traj - j_traj * (t - t2);
        traj[0] = v_0 + 0.5f * j_traj_1 * t1 * t1 + a_traj * (t2 - t1) + a_traj * (t - t2) - 0.5f * j_traj * (t - t2) * (t - t2) + vec_out[2] * t1;
    }
    else {
        traj[2] = 0.0f;
        traj[1] = 0.0f;
        traj[0] = v_target;
    }

    memmove(debug, vec_old, sizeof(vec_old[0]) * VEC_SIZE);
}