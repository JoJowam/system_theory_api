#include "exponentialFlow.hpp"
#include "system.hpp"

ExponentialFlow::ExponentialFlow() 
    : Flow() {}

ExponentialFlow::ExponentialFlow(const string& name, System* source, System* destination) 
    : Flow(name, source, destination) {}

ExponentialFlow::ExponentialFlow(const ExponentialFlow& other) 
    : Flow(other) {}

ExponentialFlow& ExponentialFlow::operator=(const ExponentialFlow& other) {
    if (this != &other) {
        Flow::operator=(other);
    }
    return *this;
}

ExponentialFlow::~ExponentialFlow() {}

double ExponentialFlow::equation() const {
    if (source != nullptr) {
        return 0.01 * source->getValue();
    }
    return 0.0;
}