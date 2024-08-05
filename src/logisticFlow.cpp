#include "logisticFlow.hpp"
#include "system.hpp"

LogisticFlow::LogisticFlow() 
    : Flow() {}

LogisticFlow::LogisticFlow(const string& name, System* source, System* destination) 
    : Flow(name, source, destination) {}

LogisticFlow::LogisticFlow(const LogisticFlow& other) 
    : Flow(other) {}

LogisticFlow& LogisticFlow::operator=(const LogisticFlow& other) {
    if (this != &other) {
        Flow::operator=(other);
    }
    return *this;
}

LogisticFlow::~LogisticFlow() {}

double LogisticFlow::equation() const {
    if (source != nullptr) {
        return 0.01 * destination->getValue() * (1 - destination->getValue() / 70);
    }
    return 0.0;
}