#include "models.h"
// #include <cppyabm/batch_runner_serial.h>
#include "batch_runner_parallel.h"
#include <iostream>
#include <fstream>
using namespace std;

// Here we are going to summarize a few things that I learned reading the paper that explains hoe cppyabm works

// there are three classes, Patch, Agent and Env. The "multi-patch" object can allow agents to be "residents" of it. 
// This sounds like it will make sense to implement the commons as (multi-) patches, humans as agents and the enviroment as env

// Agents  -> Humans
// Patches -> Commons
// Env     -> Enviroment

int main(){

    
    return(0);
}