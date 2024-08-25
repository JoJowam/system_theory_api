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
 * 
 * The Flow class acts as an abstract base class for various types of flows that can exist within the 
 * simulation. It provides a standardized interface for working with flows, ensuring that derived 
 * classes implement the necessary functionality to calculate the flow between systems.
 * 
 * @note Derived classes should ensure that the `equation` method is implemented correctly, as it is 
 * critical to the simulation's accuracy.
 * 
 * @see System
 * @author Josué Vila Real de Almeida
 * @date 2024-08-19
 * @version 0.1.3
 */
class Flow {
    public:
        /**
         * @brief Virtual destructor for the Flow class.
         * @details Ensures derived classes are properly destroyed.
         * @return None.
         * 
         * @note The destructor is virtual to allow for proper cleanup of derived class resources.
         */
        virtual ~Flow() {}

        /**
         * @brief Retrieves the name of the flow.
         * @return The flow's name as a constant reference to a string.
         * 
         * @note The name is used primarily for identification and tracking purposes within the simulation model.
         */
        virtual const string& getName() const = 0;

        /**
         * @brief Sets the source system of the flow.
         * @details Assigns the source system from which resources or energy will flow.
         * @param source A pointer to the source system.
         * @return None.
         * 
         * @note It is important to ensure that the source system is not null before performing flow calculations.
         */
        virtual void setSource(System* source) = 0;

        /**
         * @brief Sets the destination system of the flow.
         * @details Assigns the destination system to which resources or energy will flow.
         * @param destination A pointer to the destination system.
         * @return None.
         * 
         * @note It is important to ensure that the destination system is not null before performing flow calculations.
         */
        virtual void setDestination(System* destination) = 0;

        /**
         * @brief Gets the source system of the flow.
         * @details Returns the system from which resources or energy are flowing.
         * @return A pointer to the source system.
         * 
         * @note The source system is where the resources or energy originate in the flow.
         */
        virtual System* getSource() const = 0;

        /**
         * @brief Gets the destination system of the flow.
         * @details Returns the system to which resources or energy are flowing.
         * @return A pointer to the destination system.
         * 
         * @note The destination system is where the resources or energy are delivered (or not) in the flow.
         */
        virtual System* getDestination() const = 0;

        /**
         * @brief Calculates the flow between the source and destination systems.
         * @details Derived classes must override this method to define the specific flow calculation.
         * @return The calculated value representing the flow of resources or energy.
         * 
         * @note The accuracy of the simulation depends heavily on the correct implementation of this method.
         * @warning The `equation` method must be implemented by all derived classes, otherwise, the simulation will be incomplete.
         */
        virtual double equation() const = 0;
};

#endif