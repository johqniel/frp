#include <random>
#include <vector>
#include <chrono>

// In this file the equations for updating the agents are saved as functions

// the following function computes the new values of the personal characteristics of each agent of type human which are: 
// eco-level, ego level, leisure-level, and prod-level
// the ego level should be updated last because the "old ego level"
// is relevant for updating the other levels.

// it appears in the source code as if these are only updated every four ticks. 
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

