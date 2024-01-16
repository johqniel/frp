#include "bases.h"
#include "mesh.h"
#include <random>
#include <vector>
#include <chrono>

struct PARAMS{
    // the "static" thing in front of the var declarations makes that whenever we change them later
    // it will be changed for all intances of the PARAMS struct

    
    // VARIABLE DECLARATION                                 // VARIABLE NAME IN ODD                   // FURTHER EXPLANATIONS
    // -------------------------------------------------------------------------------------------------------------------------------------------------------------
    // System Setup
    static unsigned sim_length;                                                                       // how long the simulation shall run
    static unsigned pop_size;                               // Population size                        // how many agents we initialize the simulation with
    
    static unsigned num_ERGs;                               // Number of ERGs                         // number of commons of type _...
    static unsigned num_ESGs;                               // Number of ESGs  
    static unsigned num_LMGs;                               // Number of LMGs 
    static unsigned num_CMGs;                               // Number of CMGs 

    static unsigned num_PMG_sectors;                        // Number of PMG sectors                 // number of sub-common-type "PMG"
                                                                                                     // the latter would be nice to be changable outside of code
                                                                                                     // this shall be made possible at some point but for now 6 
                                                                                                     // as default is okay
    static unsigned* num_PMGs_per_sector;                    // Number of PMGs per sector
                                           
    static unsigned num_connections;                        // Number of connections
    static unsigned initial_culture_inventory;              // initial level of culure inventories
    static float waste_rate_culture_inventory;              // Waste rate of culutre inventories


    // Enviroment Setup

    static unsigned initial_poll_level;                     // Initial level of pollution
    static unsigned initial_sink_level;                     // Initial Level of sinks
    static unsigned sink_productivity;                      // Sink productivity
    static float pollution_multiplier;                      // Pollution multiplier

    // Agents Setup
            // Idk yet if we want the params for the agents 
            // to be static or if we want them to be able to 
            // be different for each agent.
        
            // I think that I have sorted the different params
            // such that parrams that may differ between 
            // individuals are not static.

        // static
    static unsigned tcm_min;                                 // tcm minimum                          //  Minimum demand of transpersonal care means
    static unsigned icm_min;                                 // icm minimum                          //  Minimum demand of interpersonal care means  
    static unsigned lm_min;                                  // lm minimum                           //  Minimum demand of life means

    static unsigned initial_tcm_demand;                                                              // Initial demand of tcm
    static unsigned initial_icm_demand;                                                              // Initial demand of icm
    static unsigned initial_lm_demand;                                                               // Initial demand of lm

    static float prob_care_need;                                                                     // Probability for care need
    static float link_care_demand_time_spent;                                                        // Link between care demand and time spent by agents
    
    static float agent_to_group_adaptation_rate;
    static float agent_prio_adaptaion_rate;
    static float multiplier_severity_extra_care;

        // not static 
    float severity_care_need;

        // not static culture specific
    float ego_level;
    float leisure_level;
    float eco_level;
    float prod_level;

    float culture_trends;





};

unsigned PARAMS::sim_length = 100;
unsigned PARAMS::pop_size = 100;

struct world;
struct human;
struct common;

using DataType = std::map<std::string,std::vector<float>>;
 
// The previous line declares the Alias "DataType" to be the type: f : std::string -> std::vector<float>

struct random{
    static double randrange(double min, double max){
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

struct common: public Patch<world,human,common>{
    using basePatch = Patch<world,human,common>;
    void step();
    bool occupied_fully;
    bool empty;
};

struct human: public Agent<world,human,common>{
    using baseAgent = Agent<world,human,common>;
    void step();

};

struct world: public Env<world,human,common>{

    using baseEnv = Env<world,human,common>;

    world():Env<world,human,common>(){
    };

    void setup_humans(){

    };
    void setup_commons(){

    };
};