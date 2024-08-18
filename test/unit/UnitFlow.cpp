#include "UnitFlow.hpp"

/**
 * @class TestFlowImpl
 * @brief Subclass of FlowImpl for testing purposes.
 * Implements the pure virtual method `equation` from FlowImpl.
 * @see FlowImpl
 * @test 
*/
class TestFlowImpl : public FlowImpl {
public:
    TestFlowImpl(const std::string& name = "", System* source = nullptr, System* destination = nullptr)
        : FlowImpl(name, source, destination) {}

    double equation() const override { return 1.0; }
}; 

void UnitFlow::runTests() {
    testGetName();
    testGetSource();    
    testGetDestination();
    testSetSource();
    testSetDestination();
    testEquation();
}

void UnitFlow::testGetName() {
    TestFlowImpl flow("TestGetNameFlow");
    assert(flow.getName() == "TestGetNameFlow");

    std::cout << "FlowImpl::getName() passed.\n";
}

void UnitFlow::testGetSource() {
    SystemImpl source("TestGetSourceSystem", 100.0);
    TestFlowImpl flow("TestGetSourceFlow", &source, nullptr);
    assert(flow.getSource() == &source);

    std::cout << "FlowImpl::getSource() passed.\n";
}

void UnitFlow::testGetDestination() {
    SystemImpl destination("TestGetDestinationSystem", 100.0);
    TestFlowImpl flow("TestGetDestinationFlow", nullptr, &destination);
    assert(flow.getDestination() == &destination);

    std::cout << "FlowImpl::getDestination() passed.\n";
}

void UnitFlow::testSetSource() {
    SystemImpl source("TestSetSourceSystem", 100.0);
    TestFlowImpl flow;
    flow.setSource(&source);
    assert(flow.getSource() == &source);

    std::cout << "FlowImpl::setSource() passed.\n";
}

void UnitFlow::testSetDestination() {
    SystemImpl destination("Destination", 50.0);
    TestFlowImpl flow("TestSetDestinationFlow");
    flow.setDestination(&destination);
    assert(flow.getDestination() == &destination);

    std::cout << "FlowImpl::setDestination() passed.\n";
}

void UnitFlow::testEquation() {
    TestFlowImpl flow("TestEquationFlow");
    assert(flow.equation() == 1.0);

    std::cout << "FlowImpl::equation() passed.\n";
}
