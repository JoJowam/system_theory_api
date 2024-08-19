#ifndef SYSTEM_IMPL_HPP
#define SYSTEM_IMPL_HPP

#include "System.hpp"

using std::string;

/**
 * @class SystemImpl
 * @brief Concrete implementation of the System interface.
 * @details SystemImpl provides a concrete implementation of the System interface, 
 * managing the name and value of the system. 
 * 
 * The SystemImpl class is responsible for maintaining the state of a system within the 
 * simulation, including its name and current value. It offers constructors for various 
 * initialization scenarios and provides a copy constructor and assignment operator for 
 * managing system state.
 * 
 * @note This class is designed to be used in conjunction with other components like Flow and Model.
 * @warning Ensure that the system's value is set appropriately before executing the simulation.
 * @date 2024-08-19
 * @version 0.1.3
 */
class SystemImpl : public System {
    friend class UnitSystem;

    private:
        string name;    /**< Name of the system. */
        double value;   /**< Current value of the system. */

    public:
        /**
         * @brief Default constructor for the SystemImpl class.
         * @details Initializes a SystemImpl object with an empty name and a value of 0.
         * 
         * @note This constructor allows for the creation of an uninitialized SystemImpl instance, 
         * which can be configured later.
         * 
         * @code
         * System* system = new SystemImpl();
         * system->setName("Example System");
         * system->setValue(10.0);
         * @endcode
         */
        SystemImpl();

        /**
         * @brief Constructs a SystemImpl with a specified name.
         * @details Initializes the system with the given name and a default value of 0.
         * @param name The name of the system.
         * 
         * @note The name helps in identifying the system within a larger simulation model.
         * 
         * @code
         * System* system = new SystemImpl("Example System");
         * @endcode
         */
        SystemImpl(const string& name);

        /**
         * @brief Constructs a SystemImpl with a name and value.
         * @details Initializes a SystemImpl object with a given name and value.
         * @param name The system's name.
         * @param value The initial value of the system.
         * 
         * @note This constructor is useful for initializing a system with a predefined state.
         * 
         * @code
         * System* system = new SystemImpl("Example System", 10.0);
         * @endcode
         */
        SystemImpl(const string& name, double value);

        /**
         * @brief Copy constructor for the SystemImpl class.
         * @details Initializes a SystemImpl object as a copy of another SystemImpl object.
         * @param other SystemImpl object to copy.
         * 
         * @note The copy constructor ensures that a deep copy of the system's state is made.
         * 
         * @code
         * System* originalSystem = new SystemImpl("Original System", 5.0);
         * System* copiedSystem = new SystemImpl(*originalSystem);
         * @endcode
         */
        SystemImpl(const SystemImpl& other);

        /**
         * @brief Assignment operator for the SystemImpl class.
         * @details Assigns values from another SystemImpl object to this one.
         * @param other Another instance of SystemImpl to be assigned.
         * @return A reference to this SystemImpl instance.
         * 
         * @note The assignment operator should handle self-assignment and ensure that all resources are properly managed.
         * 
         * @code
         * System* system1 = new SystemImpl("System 1", 10.0);
         * System* system2 = new SystemImpl("System 2", 20.0);
         * system2 = system1;
         * @endcode
         */
        SystemImpl& operator=(const SystemImpl& other);

        /**
         * @brief Destructor for the SystemImpl class.
         * @details Ensures that resources allocated by the SystemImpl instance are properly cleaned up.
         * 
         * @note The destructor must ensure that any dynamic memory or resources are released to avoid memory leaks.
         */
        virtual ~SystemImpl();

        const string getName() const override;
        double getValue() const override;
        void setValue(double value) override;
};

#endif