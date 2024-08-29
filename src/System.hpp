#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <string>

using std::string;

/**
 * @class System
 * @brief Represents an individual system within a simulation model.
 * @details The System class encapsulates the state of a system, 
 * including its name and a value representing the current state or 
 * quantity being modeled. This value can be modified or retrieved as needed.
 * 
 * The System class is an abstract interface that must be implemented by a concrete class. 
 * It serves as the foundation for any system within the simulation framework, 
 * allowing for consistent management and interaction of systems through defined flows.
 * 
 * @note The name of the system helps in identifying different systems within the model.
 * The value of the system represents the state or quantity of energy being modeled.
 * @see Flow
 * @see Model
 * @date 2024-08-19
 * @version 0.1.3
 */
class System {
    public:
        /**
         * @brief Virtual destructor for the System class.
         * @details Ensures proper cleanup of resources in derived classes.
         * 
         * @note The destructor is virtual to allow for proper destruction of derived classes.
         */
        virtual ~System() {}

        /**
         * @brief Gets the name of the system.
         * @details Returns the name of the system.
         * @return The name of the system as a string.
         * 
         * @note The name is used for identification within the simulation framework.
         */
        virtual const string getName() const = 0;

        /**
         * @brief Retrieves the current value of the system.
         * @details Returns the value of the system.
         * @return The value of the system as a double.
         * 
         * @note This value represents the state or quantity being modeled by the system.
         */
        virtual double getValue() const = 0;

        /**
         * @brief Sets the current value of the system.
         * @details Sets the value of the system to a given value.
         * @param value The new value to be assigned to the system.
         * @return None.
         * 
         * @note Changing the system's value directly affects the simulation outcome.
         */
        virtual void setValue(double value) = 0;
};

#endif