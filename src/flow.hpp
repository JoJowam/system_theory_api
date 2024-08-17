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

class Flow{
    protected:
        string name; /**< Name of the flow. */
        System* source; /**< Source system of the flow. */
        System* destination; /**< Destination system of the flow. */

    public:
        /**
         * @brief Default constructor for the Flow class.
         * @details Initializes a Flow object with an empty name and null pointers for the source and destination systems.
         */
        Flow();

        /**
         * @brief Constructs a Flow with a specified name, source, and destination systems.
         * @details If the source or destination is not provided, they are initialized to null.
         * @param name The name identifier for the flow.
         * @param source Pointer to the source system (optional, default is nullptr).
         * @param destination Pointer to the destination system (optional, default is nullptr).
         */
        Flow(const string& name, System* source = nullptr, System* destination = nullptr);

        /**
         * @brief Constructs a Flow with a specified name.
         * @details Initializes the flow with the given name and no source or destination.
         * @param name The name identifier for the flow.
         */
        Flow(const string& name);

        /**
         * @brief Copy constructor for the Flow class.
         * @details Initializes a Flow object as a copy of another Flow object.
         * @param other Flow object to copy.
         */
        Flow(const Flow& other);

        /**
         * @brief Assignment operator for the Flow class.
         * @details Assigns one Flow object to another.
         * @param other Another instance of Flow to be assigned.
         * @return A reference to this Flow instance.
         */
        Flow& operator=(const Flow& other);

        /**
         * @brief Destructor for the Flow class.
         * @details Destroys a Flow object.
         * @return None.
         */
        virtual ~Flow();

        /**
         * @brief Retrieves the name of the flow.
         * @return The flow's name as a constant reference to a string.
         */
        const string& getName() const;

        /**
         * @brief Gets the source system of the flow.
         * @details Returns the source system of the flow.
         * @return A pointer to the source system.
         */
        System* getSource() const;

        /**
         * @brief Gets the destination system of the flow.
         * @details Returns the destination system of the flow.
         * @return A pointer to the destination system.
         */
        System* getDestination() const;

        /**
         * @brief Sets the source system of the flow.
         * @details Sets the value of the system to a given value.
         * @param source A pointer to the source system.
         * @return None.
         */
        void setSource(System* source);

        /**
         * @brief Sets the destination system of the flow.
         * @details Sets the value of the system to a given value.
         * @param destination a pointer to the destination system.
         * @return None.
         */
        void setDestination(System* destination);

        /**
         * @brief Calculates the flow between the source and destination systems.
         * @details Derived classes must override this method to define the specific flow calculation.
         * @return The flow energy value tranference between the source and destination systems.
         */
        virtual double equation() const = 0;
};

#endif