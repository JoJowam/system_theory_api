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
 */
class System {
    public:
        virtual ~System() {}

        /**
         * @brief Gets the name of the system.
         * @details Returns the name of the system.
         * @return The name of the system as a string.
        */
        virtual const string getName() const = 0;

        /**
         * @brief Retrieves the current value of the system.
         * @details Returns the value of the system.
         * @return The value of the system as a double.
        */
        virtual double getValue() const = 0;

        /**
         * @brief Sets the current value of the system.
         * @details Sets the value of the system to a given value.
         * @param value The new value to be assigned to the system.
         * @return None.
        */
        virtual void setValue(double value) = 0;
};

#endif
