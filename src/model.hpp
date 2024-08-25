#ifndef MODEL_HPP
#define MODEL_HPP

#include "Flow.hpp"

#include <string>
#include <vector>

using std::string;
using std::vector;

class System;
class Flow;

/**
 * @class Model
 * @brief Represents a simulation model containing systems and flows.
 * @details The Model class manages collections of System and Flow objects. 
 * It can execute the model over a defined time period, applying the flow equations 
 * to the systems at each time step to simulate dynamic behavior.
 * 
 * The Model class provides a framework for defining and executing a simulation, managing 
 * the interactions between various systems through defined flows. This class is abstract 
 * and should be extended to implement specific simulation models.
 * 
 * @note The execute method is crucial for running the simulation and applying dynamic changes to the systems.
 * 
 * @see System 
 * @see Flow
 * @author Josué Vila Real de Almeida
 * @date 2024-08-18
 * @version 0.1.3
 */
class Model {
    public:
        /**
         * @brief Virtual destructor for the Model class.
         * @details Ensures derived classes are properly destroyed.
         * @return None.
         * 
         * @note The destructor is virtual to allow for proper cleanup of derived class resources.
         */
        virtual ~Model() {}

        /**
         * @brief Creates a new system within the model.
         * @details Creates a new system object with the specified name and value, 
         * and adds it to the model.
         * @param name The name of the system to be created.
         * @param value The initial value of the system.
         * @return A pointer to the newly created system.
         * 
         * @note The system is automatically added to the model upon creation.
         */
        virtual System* createSystem(const string& name, double value) = 0;
        
        /**
         * @brief Creates a new flow within the model.
         * @details Creates a new flow object of the specified type, with the given name, source, and destination systems.
         * @tparam T The type of flow to be created.
         * @param name The name of the flow to be created.
         * @param source Pointer to the source system of the flow.
         * @param destination Pointer to the destination system of the flow.
         * @return A pointer to the newly created flow.
         * 
         * @note The flow is automatically added to the model upon creation.
         */
        template <typename T>
        T* createFlow(const string& name, System* source, System* destination) {
            static_assert(std::is_base_of<Flow, T>::value, "T must be derived from Flow");
            T* flow = new T(name, source, destination);
            add(flow);
            return flow;
        }

        /**
         * @brief Adds a system to the model.
         * @details Adds a system to the model by storing a pointer to the system in the systems vector.
         * @param system Pointer to the system to be added.
         * @return None.
         * 
         * @note The system must be correctly initialized before adding it to the model to ensure proper simulation behavior.
         */
        virtual void add(System* system) = 0;

        /**
         * @brief Adds a flow to the model.
         * @details Adds a flow to the model by storing a pointer to the flow in the flows vector.
         * @param flow Pointer to the Flow object to be added.
         * @return None.
         * 
         * @note The flow must be properly configured, with source and destination systems set, before adding it to the model.
         */
        virtual void add(Flow* flow) = 0;

        /**
         * @brief Sets the name of the model.
         * @param modelName Name of the model.
         * @return None.
         * 
         * @note The name is used primarily for identification purposes within the simulation framework.
         */
        virtual void setName(const string& modelName) = 0;

        /**
         * @brief Gets the name of the model.
         * @return The name of the model.
         * 
         * @note The name helps in identifying the model.
         */
        virtual string getName() const = 0;

        /**
         * @brief Gets the current time of the model.
         * @return The current time of the model.
         * 
         * @note The current time is integral to determining the progress and state of the simulation.
         */
        virtual int getCurrentTime() const = 0;

        /**
         * @brief Sets the current time of the model.
         * @param time The time to be set as current time.
         * @return None.
         * 
         * @note Setting the correct current time is used for accurate simulation and continuity.
         */
        virtual void setCurrentTime(int time) = 0;

        /**
         * @brief Executes the model simulation over a specified time range.
         * @details Iterates over each time step, applying flow equations to the systems to simulate the dynamic behavior of the model.
         * @param startTime The time at which the model execution begins.
         * @param endTime The time at which the model execution ends.
         * @param timeStep The increment in time between each execution step.
         * @return None.
         * 
         * @note The execution method is the core of the simulation, driving the progression of time and system states.
         * @warning Ensure that the time range and time step are set correctly to avoid simulation errors.
         */
        virtual void execute(int startTime, int endTime, int timeStep) = 0;
};

#endif