#include "profile_generator.h"

void profile_generator_refac(
    float traj[VEC_SIZE],
    float debug[VEC_SIZE],
    const float vec_in[VEC_SIZE],
    const char override,
    const params_t *params
) {
    static float t = 0.0f;
    static char override_old = 0;

    static float vec_out[] = {0.0f, 0.0f, 0.0f};

    static float a_traj, j_traj, j_traj_1;
    static float t1, t2, t3;

    if (override == 2) {
        if (vec_in[0] != vec_out[0] || override > override_old) {
            memcpy(vec_out, vec_in, sizeof(vec_in[0]) * VEC_SIZE);
            t = 0.0f;

            float v_diff = vec_out[0] - vec_out[1];  //v_target - v_0; vec_out[0]=v_target; vec_out[1]=v_0; vec_out[2]=a_0;

            if (fabsf(v_diff) <= 0.1f) {
                a_traj = 0.0f;
                j_traj = 0.0f;
            }
            else {
                a_traj = (v_diff > 0) ? params->a_max : -params->a_max;
                j_traj = (v_diff > 0) ? params->j_max : -params->j_max;
            }

            float a_diff = a_traj - vec_out[2];
            t1 = fabsf(a_diff / params->j_max);
            j_traj_1 = (a_diff < 0) ? -params->j_max : ((a_diff == 0) ? 0.0f : params->j_max);

            float v_1 = 0.5f * j_traj_1 * t1 * t1 + vec_out[2] * t1;
            t3 = params->a_max / params->j_max;
            float v_3 = 0.5f * j_traj * t3 * t3;

            float t23 = (v_diff - v_1 - v_3) / a_traj;

            if (t23 < 0) {
                //t1 = -vec_out[2] / j_traj_1 + sqrtf(vec_out[2] * vec_out[2] / (2 * j_traj_1 * j_traj_1) + v_diff / j_traj_1);
                //t3 = t1 + sqrtf(vec_out[2] * vec_out[2] / (2 * j_traj_1 * j_traj_1) + v_diff / j_traj_1);

                t3 = sqrtf(vec_out[2] * vec_out[2] / (2 * j_traj_1 * j_traj_1) + v_diff / j_traj_1);
                t1 = -vec_out[2] / j_traj_1 + t3;
                t3 = t1 + t3;

                debug[0] = t1;
                debug[1] = t3;
                debug[2] = t23;

                t23 = 0.0f;

                a_traj = j_traj_1 * t1 + vec_out[2];
                t2 = t1 + t23;
            }
            else {
                t2 = t1 + t23;
                t3 = t2 + t3;

                debug[0] = 5.12345f;
                debug[1] = 5.12345f;
                //debug[2] = 5.12345f;
            }
        }
        else {
            t += params->t_s;
        }

        if (t < t1) {
            traj[2] = j_traj_1;                                                 //j_ref
            traj[1] = j_traj_1 * t + vec_out[2];                                //a_ref
            traj[0] = 0.5f * j_traj_1 * t * t + vec_out[2] * t + vec_out[1];    //v_ref
        }
        else if (t < t2) {
            traj[2] = 0.0f;
            traj[1] = a_traj;
            traj[0] = a_traj * (t - t1) + 0.5f * j_traj_1 * t1 * t1 + vec_out[1] + vec_out[2] * t1;
        }
        else if (t < t3) {
            traj[2] = -j_traj;
            traj[1] = a_traj - j_traj * (t - t2);
            traj[0] = vec_out[1] + 0.5f * j_traj_1 * t1 * t1 + a_traj * (t2 - t1) + a_traj * (t - t2) - 0.5f * j_traj * (t - t2) * (t - t2) + vec_out[2] * t1;
        }
        else {
            traj[2] = 0.0f;
            traj[1] = 0.0f;
            traj[0] = vec_out[0];
        }
        debug[2] = t;
    }
    else {
        traj[2] = 0.0f;
        traj[1] = vec_in[2];
        traj[0] = vec_in[1];
    }
    override_old = override;
}