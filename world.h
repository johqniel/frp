#include "bases.h"
#include "mesh.h"
#include <random>
#include <vector>
#include <chrono>

struct PARAMS{
    static unsigned sim_length;       // how long the simulation shall run
    static unsigned initial_agents;   // how many agents we initialize the simulation with

};

unsigned PARAMS::sim_length = 100;
unsigned PARAMS::initial_agents = 100;

struct world;
struct human;
struct common;

using DataType = std::map<std::string,std::vector<float>>;
 
// The previous line declares the Alias "DataType" to be the type: f : std::string -> std::vector<float>

struct random{
    static double randrage(double min, double max){
        std::random_device rd;                         // get seed from op-system
        std::mt19937 gen(rd());                        // gen is now random number generator engine
        std::uniform_real_distribution<> dis(min,max); // generate random double
        return dis(gen);
    };
    static double randint(int min, int max){
        return rand()%(max-min + min);                 // generate and return random int
    };
    static int choice(vector<int> list){
        std::random_device rd;
        std::mt19937 gen(rd());                                    // like above
        std::discrete_distribution<> dis(list.begin(),list.end()); // create random dis based on weights in vector "list"
        return list[dis(gen)];                                     // return random int from vector
    };
};