#ifndef SYSTEM_IMPL_HPP
#define SYSTEM_IMPL_HPP

#include "System.hpp"

using std::string;

/**
 * @class SystemImpl
 * @brief Concrete implementation of the System interface.
 * @see System
 */
class SystemImpl : public System {
    friend class UnitSystem;
    private:
        string name;    /**< Name of the system. */
        double value;   /**< Current energy value of the system. */

    public:
        /**
         * @brief Default constructor for the System class.
         * @details Initializes a System object with an empty name and a value of 0.
        */
        SystemImpl();

        /**
         * @brief Constructs a system with a specified name.
         * @details Initializes the system with the given name and a default value of 0.
         * @param name The name of the system.
        */
        SystemImpl(const string& name);

        /**
         * @brief Constructs a system with a name and value.
         * @details Initializes a System object with a given name and value.
         * @param name The system's name.
         * @param value The initial value of the system.
        */
        SystemImpl(const string& name, double value);

        /**
         * @brief Copy constructor for the System class.
         * @details Initializes a System object as a copy of another System object.
         * @param other System object to copy.
         * @return System object.
        */
        SystemImpl(const SystemImpl& other);

        /**
         * @brief Assignment operator for the System class.
         * @details Assigns values from another system to this one.
         * @param other Another instance of System to be assigned.
         * @return A reference to this System.
        */
        SystemImpl& operator=(const SystemImpl& other);

        virtual ~SystemImpl();

        const string getName() const override;
        double getValue() const override;
        void setValue(double value) override;
};

#endif
