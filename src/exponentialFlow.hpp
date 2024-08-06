#ifndef EXPONENTIAL_FLOW_HPP
#define EXPONENTIAL_FLOW_HPP

#include "flow.hpp"

class ExponentialFlow : public Flow {
    public:
        ExponentialFlow();
        ExponentialFlow(const string& name, System* source = nullptr, System* destination = nullptr);
        ExponentialFlow(const ExponentialFlow& other);
        ExponentialFlow& operator=(const ExponentialFlow& other);
        virtual ~ExponentialFlow();

        double equation() const override;    
};

#endif