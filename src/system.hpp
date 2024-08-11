#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>
#include <string>

using std::string;

class flow;

/**
 * @class System
 * @brief Represents an individual system within a simulation model.
 * @details The System class encapsulates the state of a system, 
 * including its name and a value representing the current state or 
 * quantity being modeled. This value can be modified or retrieved as needed.
 */
class System {
    private:
        string name; /**< Name of the system. */
        double value; /**< Current energy value of the system. */

    public:
        /**
         * @brief Default constructor for the System class.
         * @details Initializes a System object with an empty name and a value of 0.
         */
        System();

        /**
         * @brief Constructs a system with a specified name.
         * @details Initializes the system with the given name and a default value of 0.
         * @param name The name of the system.
         */
        System(const string& name);

        /**
         * @brief Constructs a system with a name and value.
         * @details Initializes a System object with a given name and value.
         * @param name The system's name.
         * @param value The initial value of the system.
         */
        System(const string& name, double value);

        /**
         * @brief Copy constructor for the System class.
         * @details Initializes a System object as a copy of another System object.
         * @param other System object to copy.
         * @return System object.
         */
        System(const System& other);

        /**
         * @brief Assignment operator for the System class.
         * @details Assigns values from another system to this one.
         * @param other Another instance of System to be assigned.
         * @return A reference to this System.
         */
        System& operator=(const System& other);

        /**
         * @brief Destructor for the System class.
         * @details Destroys a System object.
         * @return None.
         */
        virtual ~System();

        /**
         * @brief Gets the name of the system.
         * @details Returns the name of the system.
         * @return The name of the system as a string.
         */
        const string getName() const;

        /**
         * @brief Retrieves the current value of the system.
         * @details Returns the value of the system.
         * @return The value of the system as a double.
         */
        double getValue() const;

        /**
         * @brief Sets the current value of the system.
         * @details Sets the value of the system to a given value.
         * @param value The new value to be assigned to the system.
         * @return None.
         */
        void setValue(double value);
};

#endif