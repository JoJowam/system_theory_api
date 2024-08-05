#ifndef LOGISTIC_FLOW_HPP
#define LOGISTIC_FLOW_HPP

#include "flow.hpp"

class LogisticFlow : public Flow {
    public:
        LogisticFlow();
        LogisticFlow(const string& name, System* source = nullptr, System* destination = nullptr);
        LogisticFlow(const LogisticFlow& other);
        LogisticFlow& operator=(const LogisticFlow& other);
        ~LogisticFlow();

        double equation() const override;    
};

#endif