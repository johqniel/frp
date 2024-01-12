//#include "models.h"
#include "world.h" // we build this file following models.h
// #include <cppyabm/batch_runner_serial.h>
//#include "batch_runner_parallel.h"
// we dont need the above for now.
#include <iostream>
#include <fstream>
using namespace std;

// Here we are going to summarize a few things that I learned reading the paper that explains hoe cppyabm works

// there are three classes, Patch, Agent and Env. The "multi-patch" object can allow agents to be "residents" of it. 
// This sounds like it will make sense to implement the commons as (multi-) patches, humans as agents and the enviroment as env

// Agents  -> Humans
// Patches -> Commons
// Env     -> Enviroment

void test_random_struct(double d_min = 0.5, 
                        double d_max = 1.5, 
                        int i_min = 1, 
                        int i_max = 100, 
                        std::vector<int> int_array = {0,1,2,3,4,5,6,7,8,9}){

    double rand_value = random::randrange(d_min,d_max);
    std::cout << rand_value << std::endl;

    int rand_int = random::randint(i_min,i_max);
    std::cout << rand_int << std::endl;

    std::vector<int> mylist = int_array;
    int rand_choice = random::choice(mylist);
    std::cout << rand_choice << std::endl;
};

int main(){
    // test the random struct from models.h from examples
    test_random_struct();
    return(0);
}