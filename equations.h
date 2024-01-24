#include "random_number_generators.h"

#include <random>
#include <vector>
#include <chrono>

// In this file the equations for updating the agents are saved as functions

// the following function computes the new values of the personal characteristics of each agent of type human which are: 
// eco-level, ego level, leisure-level, and prod-level
// the ego level should be updated last because the "old ego level"
// is relevant for updating the other levels.

// it appears in the source code as if these are only updated every four ticks. by generating a random float in [0,1] for each 
// agent and each characteristic and only updating when that float is smaller 1 i have to figure out how we can do that "efficiently"
// especially I would like to be able to turn that random effect on and of for testing 



// apparently w_it is infact agent specific. it is called care_impact in ODD protocoll.

float personal_characteristics(float old_level, 
                               float c_pgc_trend, 
                               float c_lgc_trend,
                               float ego_level){
    float new_level = 0.05 * (1 - ego_level);
    new_level = (0.5 * (c_pgc_trend + c_lgc_trend) - old_level) * new_level;
    new_level = old_level + new_level;
    // all characteristics are in [0,1] thus: 
    if (new_level > 1){
        new_level = 1;
    }
    if (new_level < 0){
        new_level = 0;
    }
    return(new_level); 
};

// TODO 
// it appears as if:
// 1. w_it,  a_one and maybe as well icm_min are global constant variables 
// 2. w_it = (1 - care-impact)
float icm_targets(float iCM_min, 
                  float a_one, 
                  float w_it, 
                  float ego_level){
    float new_icm_target;
    new_icm_target = 0.5 + gen_random_normal(ego_level,0.1);
    new_icm_target = icm_min * (1 + w_it * a_one * new_icm_target);
    return(new_icm_target);
};


// TODO:
// it appears as if: 
// 1. w_it and a_one and maybe also tcm_min are global constant variables 
// 2. w_it = (1 - care-impact)
float tcm_targets(float tcm_min, 
                  float a_one, 
                  float w_it){
    float new_tcm_target;
    new_tcm_target = tcm_min + tcm_min * a_one * w_it;
    return(new_tcm_target);
};

// TODO
// Though defined explicitly in ODD protocoll, in the source code this variable is not computed individually. 
// Find out why
float g_it(float lm_c_prod_group_mean, 
           float lm_c_life_group_mean,
           float lm_old,
           float ego_level,
           float e_it, 
           float eco_level){
    float g_it_;
    g_it_ = (lm_c_prod_group_mean + lm_c_life_group_mean) / 2 - lm_old;
    g_it_ = g_it_ * ego_level * e_it * gen_random_float(1 - eco_level); 
}; 

// TODO:
// it appears as if: 
// 1. w_it and a_one and are global constant variables 
// 2. w_it = (1 - care-impact)
float lm_targets(float lm_old, 
                 float ego_level, 
                 float w_it, 
                 float g_it){
    float new_lm_target;
    float upper_bound = ego_level * w_it;
    new_lm_target = 1 + gen_random_float(upper_bound) + g_it;
    new_lm_target = lm_old * new_lm_target;
    return(new_lm_target);
};

// this equation computes pt_i,t^total that doesnt get a name in ODD protocoll
// emo-impact is emo_it^mean
// the leisure_characteristic = leisure_level
float total_active_time(float leisure_characteristic, 
                        float emo_impact){
    float active_time;
    active_time = (1 + (1 - emo_impact)/2);
    active_time = 112 * (1 - leisure_characteristic) * active_time;
    return(active_time); 
};

// this function computes the variable pt_it^target which has the name productive time
// i dont quite get why it is called productive time even though it is only the time
// the agent wants to be active. 
// as above maybe we dont have to pass w_it and care_time_connex to the function
float productive_time_target(float total_active_time, 
                             float w_it, 
                             float care_time_connex){
    float time_target;
    time_target = 1 - (1 - w_it) * care_time_connex;
    time_target = total_active_time * time_target;
    return(time_target);
};

// the cond_i,t^need variable is a variable that tells us if the agent wants to decrease or increase something
// basically cond = current / target
// I actually dont know what we use it for because it doesent appear in other equation in the ODD protocoll
float compute_condition(float need_current, float need_target){
    return(need_current/need_target);
};

// I think that a_two is a global constant. 
float compute_emotions(float emotions_old, 
                       float emotions_group, 
                       float a_two, 
                       float ego_level){
    float emotions_new;
    emotions_new = (emotions_group - emotions_old);
    emotions_new = emotions_new * a_two * (1 - ego_level);
    emotions_new = emotions_old + emotions_new;
    return(emotions_new);
};



// equations for priorities (whatever that is)
// it appears as if the prioritiers have to be computed after all the other variables
// because they use the current variables. 


float compute_prio_svn_k(float prio_svn_k_old, 
                         float emotion_snv_k, 
                         float moti_snv_k){
    float prio_snv_k;
    prio_snv_k = 1 - emotion_snv_k + moti_snv_k;
    prio_snv_k = gen_random_float(prio_snv_k / 2);
    prio_snv_k = prio_svn_k_old + prio_snv_k + 0.5;
    return(prio_snv_k);
};

// I believe that a_three is a global constant
float compute_prio_lg(float prio_lg_old, 
                      float emotions_group, 
                      float a_three, 
                      float ego_level){
    float prio_lg;
    prio_lg = (1 - emotions_group) * a_three * ego_level;
    prio_lg = prio_lg_old + prio_lg;
    return(prio_lg);
};


// a_three is a global constant i believe
float compute_prio_pgs(float prio_pgs_old, float emotions_group, float a_three, float ego_level){
    float prio_pgs;
    prio_pgs = (1 - emotions_group) * a_three * (1 - ego_level);
    prio_pgs = prio_pgs_old + prio_pgs;
    return(prio_pgs);
};