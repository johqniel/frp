#include "world.h"
#include <random>
#include <vector>
#include <chrono>

void initilize_PARAMS(){

    PARAMS::num_ESGs = 1;
    // an so forth

    PARAMS::prod_group_num["ESG"] = PARAMS::num_ESGs;
    PARAMS::prod_group_num["ERG"] = PARAMS::num_ERGs;
    PARAMS::prod_group_num["CMG"] = PARAMS::num_CMGs;
    PARAMS::prod_group_num["LMG"] = PARAMS::num_LMGs;
    PARAMS::prod_group_num["PMG1"] = PARAMS::num_PMG1s;
    PARAMS::prod_group_num["PMG2"] = PARAMS::num_PMG2;
    PARAMS::prod_group_num["PMG3"] = PARAMS::num_PMG3;

}