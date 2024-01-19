#include "bases.h"
#include "mesh.h"
#include <random>
#include <vector>
#include <chrono>

struct Labour_prod{
        // We use this in the struct "PARAMS" to safe parameters that differ for the different types of productive groups

        // I dont quite understand yet why labour prod is defined for PMG1-3 even though we have 6 PMGs
        static float ESG;
        static float ERG;
        static float PMG1;
        static float PMG2;
        static float PMG3;
        static float LMG;
        static float CMG;
};

struct Prod_means_intensity{
        // We use this in the struct "PARAMS" to safe parameters that differ for the different types of productive groups
        
        // I dont quite understand yet why labour prod is defined for PMG1-3 even though we have 6 PMGs
        static float ESG;
        static float ERG;
        static float PMG1;
        static float PMG2;
        static float PMG3;
        static float LMG;
        static float CMG;
};

struct Reserve_target{
        // We use this in the struct "PARAMS" to safe parameters that differ for the different types of productive groups
        
        // I dont quite understand yet why labour prod is defined for PMG1-3 even though we have 6 PMGs
        static float ESG;
        static float ERG;
        static float PMG1;
        static float PMG2;
        static float PMG3;
        static float LMG;
        static float CMG;
};

struct Inventory_waste_rate{
        // We use this in the struct "PARAMS" to safe parameters that differ for the different types of productive groups
        
        // I dont quite understand yet why labour prod is defined for PMG1-3 even though we have 6 PMGs
        static float ESG;
        static float ERG;
        static float PMG1;
        static float PMG2;
        static float PMG3;
        static float LMG;
        static float CMG;
};

struct Depreciation_rate_p_means{
        // We use this in the struct "PARAMS" to safe parameters that differ for the different types of productive groups
        
        // I dont quite understand yet why labour prod is defined for PMG1-3 even though we have 6 PMGs
        static float ESG;
        static float ERG;
        static float PMG1;
        static float PMG2;
        static float PMG3;
        static float LMG;
        static float CMG;
};

struct Pollution_intensity{
        // We use this in the struct "PARAMS" to safe parameters that differ for the different types of productive groups
        
        // I dont quite understand yet why labour prod is defined for PMG1-3 even though we have 6 PMGs
        static float ESG;
        static float ERG;
        static float PMG1;
        static float PMG2;
        static float PMG3;
        static float LMG;
        static float CMG;
};

struct Abs_pollution_intensity{
        // We use this in the struct "PARAMS" to safe parameters that differ for the different types of productive groups
        
        // I dont quite understand yet why labour prod is defined for PMG1-3 even though we have 6 PMGs
        static float ESG;
        static float ERG;
        static float PMG1;
        static float PMG2;
        static float PMG3;
        static float LMG;
        static float CMG;
};

struct PARAMS{
    // the "static" thing in front of the var declarations makes that whenever we change them later
    // it will be changed for all intances of the PARAMS struct

    
    // VARIABLE DECLARATION                                 // VARIABLE NAME IN ODD                   // FURTHER EXPLANATIONS
    // _____________________________________________________________________________________________________________________________________________________________

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
    static unsigned* num_PMGs_per_sector;                   // Number of PMGs per sector
                                           
    static unsigned num_connections;                        // Number of connections
    static unsigned initial_culture_inventory;              // initial level of culure inventories
    static float waste_rate_culture_inventory;              // Waste rate of culutre inventories


    // Enviroment Setup
    // --------------------------------------------------------------------------------------------------------------------------------------------------------------
    static unsigned initial_poll_level;                     // Initial level of pollution
    static unsigned initial_sink_level;                     // Initial Level of sinks
    static unsigned sink_productivity;                      // Sink productivity
    static float pollution_multiplier;                      // Pollution multiplier

    // Agents Setup
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------
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
    
    static float agent_to_group_adaptation_rate;                                                     // General adaptation rate of agent-to-group values
    static float agent_prio_adaptaion_rate;                                                          // General adaption rate of agent prioritiers for life and productive groups
    static float multiplier_severity_extra_care;                                                     // Multiplier of severity of extra care demand

        // not static 
    // -------------------------------------------------------------------------------------------------------------------------------------------------------------
    float severity_care_need;

        // not static culture specific
    float ego_level;                                        // Ego level                            // The following four are the factors that determine an agents culture  
    float leisure_level;                                    // Leisure level
    float eco_level;                                        // Eco level
    float prod_level;                                       // Productivity level

    float culture_trends;                                   // Characteristic trends of cultures

    // Life Groups
    // ---------------------------------------------------------------------------------------------------------------------------------------------------------------

    static unsigned groupsize;                              // Groupsize 
    static float labour_prod_for_icm;                       // Labour productivity for production of on icm

    // Productive Groups
    // ---------------------------------------------------------------------------------------------------------------------------------------------------------------

    Labour_prod labour_prod;                                // Labour productivity
    Prod_means_intensity prod_means_intensity;              // Productive means intensity   
    Reserve_target reserve_target;                          // Reserve target
    Inventory_waste_rate inventory_waste_rate;              // Waste rate of inventory
    Depreciation_rate_p_means depreciation_rate_p_means;    // Depreciation rate of productive means
    Pollution_intensity pollution_intensity;                // Pollution intensity
    Abs_pollution_intensity abs_pollution_intensity;        // Absolute pollution intensity

    // PMG1 specific

    static float resource_intensity;                       // Resource intensity

    // ERG specific 

    static float sink_intensity;                           // Sink intensity
    


};

unsigned PARAMS::sim_length = 100;
unsigned PARAMS::pop_size = 100;

struct world;
struct agent;
struct group;


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

struct local_patch: public Patch<world,agent,local_patch>{
    using basePatch = Patch<world,agent,local_patch>;
    local_patch(shared_ptr<world> env,MESH_ITEM mesh_item):basePatch(env,mesh_item){
	}
    void step();
};

struct agent: public Agent<world,agent,local_patch>{
    using baseAgent = Agent<world,agent,local_patch>;

    agent(shared_ptr<world> env, string class_name):baseAgent(env, class_name){
    };

    void step();


    // not culture specific
    float severity_care_need;

    // culture specific
    float ego_level;                                        // Ego level                            // The following four are the factors that determine an agents culture  
    float leisure_level;                                    // Leisure level
    float eco_level;                                        // Eco level
    float prod_level;                                       // Productivity level

    float culture_trends;                                   // Characteristic trends of cultures


};


struct world: public Env<world,agent,local_patch>{

    using baseEnv = Env<world,agent,local_patch>;

    world():Env<world,agent,local_patch>(){
    };

    void reset(unsigned iter_i = 0){
		this->agents.clear();
		this->patches.clear();
		this->iter_i = iter_i;
		this->data = {{"Humans",{}},{"Lifegroups",{}},{"Productivegroups",{}},{"memory",{}}};
		this->setup_groups("life");
        this->setup_groups("productive");
		this->setup_humans();
	}

    void setup_groups(string class_name){
        if (class_name == "life"){
            this->setup_life_groups();
        }
        else if (class_name == "productive"){
            this->setup_productive_groups();
        }
        else throw;
    };

    void setup_humans(){
        string agent_name;
        agent_name = "human";
        int number = PARAMS::pop_size;
        for (unsigned i = 0; i < number; i++){
            auto a = this->generate_agent(agent_name);
            auto dest_index = random::choice(this->patches_keys);
            auto dest = this-> patches[dest_index];
            this->place_agent(dest,a,true);
        }
    };
    void setup_productive_groups(){

    };
    void setup_life_groups(){
        //int number = PARAMS::
    };

    shared_ptr<agent> generate_agent(string agent_name){
        shared_ptr<agent> obj;
        obj = make_shared<agent>(this->shared_from_this(),agent_name);
        this->agents.push_back(obj);
        return obj;
    };

    shared_ptr<local_patch> generate_patch(MESH_ITEM mesh_item){
        // We use the mesh_structure provided by 
        // Cppy even though we dont need it. 
        // Because I dont want to change their header files. 
		auto patch_obj = make_shared<local_patch>(this->shared_from_this(),mesh_item);
		this->patches[mesh_item.index] = patch_obj;
		return patch_obj;
	}


    DataType data;
	unsigned iter_i;

};