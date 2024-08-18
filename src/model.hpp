#ifndef MODEL_HPP
#define MODEL_HPP

#include "Flow.hpp"

/**
 * @class Model 
 * @brief Represents a simulation model containing systems and flows.
 * @details The Model class manages collections of System and Flow objects. 
 * It can execute the model over a defined time period, applying the flow equations 
 * to the systems at each time step to simulate dynamic behavior.
 * @see System 
 * @see Flow
*/
class Model {
    public:
        /**
         * @brief Destructor for the Model class.
         * @details Destroys a Model object.
         * @return None.
         */
        virtual ~Model() {}

        /**
         * @brief Adds a system to the model.
         * @details Adds a system to the model by storing a pointer to the system in the systems vector.
         * @param system Pointer to the system to be added.
         * @return None.
         */
        virtual void add(System* system) = 0;

        /**
         * @brief Adds a flow to the model.
         * @details Adds a flow to the model by storing a pointer to the flow in the flows vector.
         * @param flow Pointer to the Flow object to be added.
         * @return None.
         */
        virtual void add(Flow* flow) = 0;

        /**
         * @brief Executes the model simulation over a specified time range.
         * @details Iterates over each time step, applying flow equations to the systems to simulate the dynamic behavior of the model.
         * @param startTime The time at which the model execution begins.
         * @param endTime The time at which the model execution ends.
         * @param timeStep The increment in time between each execution step.
         * @return None.
         */
        virtual void execute(int startTime, int endTime, int timeStep) = 0;
};

#endif
