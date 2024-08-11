
#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using std::vector;

class System;
class Flow;

/**
 * @class Model 
 * @brief Represents a simulation model containing systems and flows.
 * @details The Model class manages collections of System and Flow objects. 
 * It can execute the model over a defined time period, applying the flow equations 
 * to the systems at each time step to simulate dynamic behavior.
 * @see System 
 * @see Flow
*/

class Model{
    private:
        vector<System*> systems; /**< Vector storing pointers to the systems within the model. */
        vector<Flow*> flows; /**< Vector storing pointers to the flows within the model. */

        typedef vector<System*>::iterator SystemIterator; /**< Typedef for an iterator for the systems vector. */
        typedef vector<Flow*>::iterator FlowIterator; /**< Typedef for an iterator for the flows vector.*/

    public:
        /**
         * @brief Default constructor for the Model class.
         * @details Initializes a Model object with no systems or flows.
         */
        Model();

        /**
         * @brief Copy constructor for the Model class.
         * @details Initializes a Model object as a copy of another Model object.
         * @param other Model object to copy.
         */
        Model(const Model& other);

        /**
         * @brief Assignment operator for the Model class.
         * @details Assigns one Model object to another.
         * @param other Another instance of Model to be assigned.
         * @return A reference to this Model instance.
         */
        Model& operator=(const Model& other);

        /**
         * @brief Destructor for the Model class.
         * @details Destroys a Model object.
         * @return None.
         */
        virtual ~Model();

        /**
         * @brief Adds a system to the model.
         * @details Adds a system to the model by storing a pointer to the system in the systems vector.
         * @param system Pointer to the system to be added.
         * @return None.
         */
        void add(System* system);

        /**
         * @brief Adds a flow to the model.
         * @details Adds a flow to the model by storing a pointer to the flow in the flows vector.
         * @param flow Pointer to the Flow object to be added.
         * @return None.
         */
        void add(Flow* flow);

        /**
         * @brief Executes the model simulation over a specified time range.
         * @details Iterates over each time step, applying flow equations to the systems to simulate the dynamic behavior of the model.
         * @param startTime The time at which the model execution begins.
         * @param endTime The time at which the model execution ends.
         * @param timeStep The increment in time between each execution step.
         * @return None.
         */
        void execute(int startTime, int endTime, int timeStep);
};

#endif