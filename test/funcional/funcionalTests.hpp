#ifndef FUNCIONAL_TESTS_HPP
#define FUNCIONAL_TESTS_HPP

#include "../../src/FlowImpl.hpp"
#include "../../src/ModelImpl.hpp"
#include "../../src/SystemImpl.hpp"

#include <iostream>
#include <cassert>
#include <string>
#include <cmath>

/**
 * @class ExponentialFlow
 * @brief Represents a flow with an exponential equation.
 * @details The ExponentialFlow class implements the equation method to 
 * calculate the flow value based on an exponential equation.
 * @see FlowImpl
 * @see SystemImpl
*/
class ExponentialFlow : public FlowImpl {
    public:
        ExponentialFlow();
        ExponentialFlow(const std::string& name, System* source = nullptr, System* destination = nullptr);
        ExponentialFlow(const ExponentialFlow& other);

        ExponentialFlow& operator=(const ExponentialFlow& other);

        virtual ~ExponentialFlow();

        /**
         * @brief Implements the equation method.
         * @details Calculates the flow value based on an exponential equation.
         * @return The calculated flow value based on equation: f = 0.01 * source->getValue().
        */
        double equation() const override;
};

/**
 * @class LogisticFlow
 * @brief Represents a flow with an exponential equation.
 * @details The LogisticFlow class implements the equation method to 
 * calculate the flow value based on an logistic equation.
 * @see FlowImpl
 * @see SystemImpl
*/
class LogisticFlow : public FlowImpl {
    public:
        LogisticFlow();
        LogisticFlow(const std::string& name, System* source = nullptr, System* destination = nullptr);
        LogisticFlow(const LogisticFlow& other);

        LogisticFlow& operator=(const LogisticFlow& other);

        virtual ~LogisticFlow();

        /**
         * @brief Implements the equation method.
         * @details Calculates the flow value based on an exponential equation.
         * @return The calculated flow value based on equation:
         * f = 0.01 * destination->getValue() * (1 - destination->getValue() / 70).
        */
        double equation() const override;
};

/**
 * @brief Tests the ExponentialFlow class.
 * @details Creates an ExponentialFlow object and tests its equation method.
*/
void exponentialFlow();

/**
 * @brief Tests the LogisticFlow class.
 * @details Creates a LogisticFlow object and tests its equation method.
*/
void logisticFlow();

/**
 * @brief Tests a complex flow scenario.
 * @details Creates a model with multiple systems and flows to test the interactions between them.
*/
void complexFlow();

#endif
