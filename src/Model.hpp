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

        typedef vector<System*>::iterator SystemIterator;    /**< Typedef for an iterator for the systems vector. */
        typedef vector<Flow*>::iterator FlowIterator;        /**< Typedef for an iterator for the flows vector. */
        
        /**
         * @brief Virtual destructor for the Model class.
         * @details Ensures derived classes are properly destroyed.
         * @return None.
         * 
         * @note The destructor is virtual to allow for proper cleanup of derived class resources.
         */
        virtual ~Model() {}

        /**
         * @brief Retrieves the singleton instance of the Model class.
         * @return A pointer to the singleton instance of the Model class.
         * 
         * @note The getInstance method provides access to the singleton instance of the Model class.
         */
        static Model* getInstance();

        /**
         * @brief Creates a new model object.
         * @details Creates a new model object with the specified name.
         * @param name The name of the model to be created.
         * @return A pointer to the newly created model.
         * 
         * @note The model is created with the given name and can be used to define and execute a simulation.
         */
        static Model* createModel(const string& name);

        /**
         * @brief Deletes the model object.
         * @return A pointer to the deleted model object.
         * 
         * @note The deleteModel method is used to destroy the singleton instance of the Model class.
         */
        static bool deleteModel();

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
         * @brief Deletes a system from the model.
         * @param name The name of the system to be deleted.
         * @return True if the system was successfully deleted, false otherwise.
         * 
         * @note The system is removed from the model's collection of systems.
         */
        virtual bool deleteSystem(System* system) = 0;

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
        T* createFlow(const string& name, System* source = nullptr, System* destination = nullptr) {
            static_assert(std::is_base_of<Flow, T>::value, "T must be derived from Flow");
            T* flow = new T(name, source, destination);
            add(flow);
            return flow;
        }

        /**
         * @brief Deletes a flow from the model.
         * @param name The name of the flow to be deleted.
         * @return True if the flow was successfully deleted, false otherwise.
         * 
         * @note The flow is removed from the model's collection of flows.
         */
        virtual bool deleteFlow(Flow* flow) = 0;

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

    protected:
        /**
         * @brief Adds a system to the model.
         * @param system The system to be added to the model.
         * @return None.
         * 
         * @note The system is added to the model's collection of systems for simulation.
         */
        virtual void add(System* system) = 0;

        /**
         * @brief Adds a flow to the model.
         * @param flow The flow to be added to the model.
         * @return None.
         * 
         * @note The flow is added to the model's collection of flows for simulation.
         */
        virtual void add(Flow* flow) = 0;
};

#endif