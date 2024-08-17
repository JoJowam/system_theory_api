#include "../../src/flow.hpp"
#include "../../src/model.hpp"
#include "../../src/system.hpp"
#include <string>

#ifndef FUNCIONAL_TESTS_HPP
#define FUNCIONAL_TESTS_HPP

/**
 * @class ExponentialFLow
 * @brief 
 * @details 
 */
class ExponentialFlow : public Flow {
    public:
        ExponentialFlow();
        ExponentialFlow(const std::string& name, System* source = nullptr, System* destination = nullptr);
        ExponentialFlow(const ExponentialFlow& other);
        ExponentialFlow& operator=(const ExponentialFlow& other);
        virtual ~ExponentialFlow();

        double equation() const override;
};

/**
 * @class LogisticFlow
 * @brief A class that implements flow's virtual methods
 * @details 
 */
class LogisticFlow : public Flow {
    public:
        LogisticFlow();
        LogisticFlow(const std::string& name, System* source = nullptr, System* destination = nullptr);
        LogisticFlow(const LogisticFlow& other);
        LogisticFlow& operator=(const LogisticFlow& other);
        virtual ~LogisticFlow();

        double equation() const override;
};


void exponentialFlow();
void logisticFlow();
void complexFlow();

#endif
