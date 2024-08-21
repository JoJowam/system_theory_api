#ifndef FUNCIONAL_TESTS_HPP
#define FUNCIONAL_TESTS_HPP

#include "../../src/FlowImpl.hpp"
#include "../../src/ModelImpl.hpp"
#include "../../src/SystemImpl.hpp"

/**
 * @class ExponentialFlow
 * @brief Represents a flow with an exponential equation.
 * @details The ExponentialFlow class models a flow where the transfer rate is proportional 
 * to the value in the source system, following an exponential decay model. This class 
 * implements the `equation` method to compute the flow value based on the formula:
 * 
 * \f[ f = 0.01 \times source->getValue() \f]
 * 
 * This type of flow is typically used in simulations where the quantity decreases 
 * exponentially over time.
 * 
 * @see FlowImpl
 * @see SystemImpl
 * @date 2024-08-19
 * @version 0.1.0
 */
class ExponentialFlow : public FlowImpl {
    public:
        /**
         * @brief Default constructor for ExponentialFlow.
         * @details Initializes an ExponentialFlow with no name and no connected systems.
         * 
         * @code
         * ExponentialFlow flow;
         * @endcode
         */
        ExponentialFlow();

        /**
         * @brief Constructs an ExponentialFlow with a name and optionally connects it to systems.
         * @param name The name of the flow.
         * @param source The source system from which the flow originates.
         * @param destination The destination system to which the flow goes.
         * 
         * @note The source and destination systems can be connected after flow creation.
         * 
         * @see System
         * @see Flow
         * 
         * @code
         * System* source = new SystemImpl("Source System");
         * System* destination = new SystemImpl("Destination System");
         * ExponentialFlow flow("My Flow", source, destination);
         * @endcode
         */
        ExponentialFlow(const std::string& name, System* source = nullptr, System* destination = nullptr);

        /**
         * @brief Copy constructor for ExponentialFlow.
         * @param other The ExponentialFlow object to be copied.
         * 
         * @note The copy constructor ensures that a shallow copy of the ExponentialFlow object is made.
         * 
         * @code
         * ExponentialFlow originalFlow("Original Flow");
         * ExponentialFlow copiedFlow = originalFlow;
         * @endcode
         */
        ExponentialFlow(const ExponentialFlow& other);

        /**
         * @brief Assignment operator for ExponentialFlow.
         * @param other The ExponentialFlow object to be assigned.
         * @return A reference to this ExponentialFlow instance.
         * 
         * @code
         * ExponentialFlow originalFlow("Original Flow");
         * ExponentialFlow copiedFlow;
         * copiedFlow = originalFlow;
         * @endcode
         */
        ExponentialFlow& operator=(const ExponentialFlow& other);

        /**
         * @brief Destructor for ExponentialFlow.
         * @details Destroys the ExponentialFlow object and frees associated resources.
         */
        virtual ~ExponentialFlow();

        /**
         * @brief Implements the equation method.
         * @details Calculates the flow value based on an exponential equation.
         * @return The calculated flow value based on the equation: 
         * \f[ f = 0.01 \times source->getValue() \f]
         * 
         * @note The flow value is directly proportional to the source system's value.
         */
        double equation() const override;
};

/**
 * @class LogisticFlow
 * @brief Represents a flow with a logistic equation.
 * @details The LogisticFlow class models a flow where the transfer rate follows 
 * a logistic growth model. This is useful in simulations where growth is initially 
 * exponential but slows as it approaches a carrying capacity. The class implements 
 * the `equation` method to compute the flow value based on the formula:
 * 
 * \f[ f = 0.01 \times destination->getValue() \times \left(1 - \frac{destination->getValue()}{70}\right) \f]
 * 
 * @see FlowImpl
 * @see SystemImpl
 * @date 2024-08-19
 * @version 0.1.0
 */
class LogisticFlow : public FlowImpl {
    public:
        /**
         * @brief Default constructor for LogisticFlow.
         * @details Initializes a LogisticFlow with no name and no connected systems.
         * 
         * @note The source and destination systems can be connected after flow creation. The default
         *  values for the source and destination systems are nullptr and the name is an empty string ''.
         * 
         * @code
         * LogisticFlow flow;
         * @endcode
         */
        LogisticFlow();

        /**
         * @brief Constructs a LogisticFlow with a name and optionally connects it to systems.
         * @param name The name of the flow.
         * @param source The source system from which the flow originates.
         * @param destination The destination system to which the flow goes.
         * 
         * @note If the source and destination systems are not provided, they are initialized to nullptr.
         * 
         * @code
         * System* source = new SystemImpl("Source System");
         * System* destination = new SystemImpl("Destination System");
         * LogisticFlow flow("My Flow", source, destination);
         * @endcode
         */
        LogisticFlow(const std::string& name, System* source = nullptr, System* destination = nullptr);

        /**
         * @brief Copy constructor for LogisticFlow.
         * @param other The LogisticFlow object to be copied.
         * 
         * @note The copy constructor ensures that a shallow copy of the LogisticFlow object is made.
         * 
         * @code
         * LogisticFlow originalFlow("Original Flow");
         * LogisticFlow copiedFlow = originalFlow;
         * @endcode
         */
        LogisticFlow(const LogisticFlow& other);

        /**
         * @brief Assignment operator for LogisticFlow.
         * @param other The LogisticFlow object to be assigned.
         * @return A reference to this LogisticFlow instance.
         * 
         * @code
         * LogisticFlow originalFlow("Original Flow");
         * LogisticFlow copiedFlow;
         * copiedFlow = originalFlow;
         * @endcode
         */
        LogisticFlow& operator=(const LogisticFlow& other);

        /**
         * @brief Destructor for LogisticFlow.
         * @details Destroys the LogisticFlow object and frees associated resources.
         */
        virtual ~LogisticFlow();

        /**
         * @brief Implements the equation method.
         * @details Calculates the flow value based on a logistic equation.
         * @return The calculated flow value based on the equation:
         * \f[ f = 0.01 \times destination->getValue() \times \left(1 - \frac{destination->getValue()}{70}\right) \f]
         */
        double equation() const override;
};

/**
 * @brief Tests the ExponentialFlow class.
 * @pre A Model object with an ExponentialFlow object connected to two System objects is created.
 * @post The Model is executed over a defined period, and the final values of the systems are checked.
 * @assert The flow value is correctly calculated based on the source system's value. The final values 
 * of the systems are verified against expected results.
 * @test Creates an ExponentialFlow object, connects it to systems, and tests its equation method. 
 * The test ensures that the flow value is computed correctly, reflecting the source system's value.
 */
void exponentialFlow();

/**
 * @brief Tests the LogisticFlow class.
 * @pre A Model object with a LogisticFlow object connected to two System objects is created.
 * @post The Model is executed over a defined period, and the final values of the systems are checked.
 * @assert The flow value is correctly calculated based on the destination system's value. The final values 
 * of the systems are verified against expected results.
 * @test Creates a LogisticFlow object, connects it to systems, and tests its equation method. 
 * The test ensures that the flow value is computed correctly, reflecting the destination system's value.
 */
void logisticFlow();

/**
 * @brief Tests a complex flow scenario.
 * @pre A Model object with multiple systems and flows, including both ExponentialFlow objects, is created.
 * @post The Model is executed over a defined period, and the final values of all systems are checked.
 * @assert The interaction of exponential flows within the model is correctly simulated. The final values of 
 * the systems are verified against expected results for a complex flow scenario involving multiple interconnected flows.
 * @test Creates a model with multiple systems and flows, including exponential flows interacting within the same model. 
 * The test verifies the correct execution of the model and ensures that the final system values are as expected.
 */
void complexFlow();

#endif