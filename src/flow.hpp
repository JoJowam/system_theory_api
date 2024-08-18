#ifndef FLOW_HPP
#define FLOW_HPP

#include <string>

class System;

using std::string;

/**
 * @class Flow
 * @brief Represents a flow of resources or energy between two systems in a simulation model.
 * @details The Flow class models the transfer of resources or energy between two systems, designated 
 * as the source and destination systems. The name of the flow helps in identifying it within the model. 
 * Derived classes must implement the equation method to define the specific calculation of the flow.
 * @see System
 */
class Flow {
    public:
        /**
         * @brief Destructor for the Flow class.
         * @details Destroys a Flow object.
         * @return None.
         */
        virtual ~Flow() {}

        /**
         * @brief Retrieves the name of the flow.
         * @return The flow's name as a constant reference to a string.
         */
        virtual const string& getName() const = 0;

        /**
         * @brief Sets the source system of the flow.
         * @details Sets the value of the system to a given value.
         * @param source A pointer to the source system.
         * @return None.
         */
        virtual void setSource(System* source) = 0;

        /**
         * @brief Sets the destination system of the flow.
         * @details Sets the value of the system to a given value.
         * @param destination a pointer to the destination system.
         * @return None.
         */
        virtual void setDestination(System* destination) = 0;

        /**
         * @brief Gets the source system of the flow.
         * @details Returns the source system of the flow.
         * @return A pointer to the source system.
         */
        virtual System* getSource() const = 0;

        /**
         * @brief Gets the destination system of the flow.
         * @details Returns the destination system of the flow.
         * @return A pointer to the destination system.
         */
        virtual System* getDestination() const = 0;

        /**
         * @brief Calculates the flow between the source and destination systems.
         * @details Derived classes must override this method to define the specific flow calculation.
         * @return The flow energy value tranference between the source and destination systems.
         */
        virtual double equation() const = 0;
};

#endif
