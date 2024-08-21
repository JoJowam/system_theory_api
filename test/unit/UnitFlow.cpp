#include "UnitFlow.hpp"

#include "../../src/FlowImpl.hpp"
#include "../../src/SystemImpl.hpp"

#include <cassert>
#include <iostream>

/**
 * @class UnitTestFlowStub 
 * @brief Subclass of FlowImpl for testing purposes.
 * @details UnitTestFlowStub  is a concrete subclass of FlowImpl used specifically for testing. 
 * It provides a simple implementation of the `equation` method, returning a constant value of 1.0, 
 * which is useful for testing the behavior of other components interacting with Flow objects.
 * @see FlowImpl
 * @see Flow
 * @test Provides a basic implementation of the `equation` method to facilitate testing of 
 * Flow-related functionality in various scenarios. This class allows for the easy verification 
 * of how other parts of the system interact with Flow objects, without the complexity of real flow calculations.
 */
class UnitTestFlowStub : public FlowImpl {
    public:
        /**
         * @brief Constructs a UnitTestFlowStub  object.
         * @param name The name of the flow (default is an empty string).
         * @param source Pointer to the source System (default is nullptr).
         * @param destination Pointer to the destination System (default is nullptr).
         */
        UnitTestFlowStub (const std::string& name = "", System* source = nullptr, System* destination = nullptr)
            : FlowImpl(name, source, destination) {}

        /**
         * @brief Provides a constant value for the flow equation.
         * @details Overrides the pure virtual method `equation` from FlowImpl. 
         * This implementation returns a constant flow value of 1.0, which is useful 
         * for testing and verifying interactions with Flow objects.
         * @return A constant value of 1.0.
         */
        double equation() const override { return 1.0; }
}; 

void UnitFlow::runUnitTests() {
    assert(unit_testGetName());
    assert(unit_testGetSource());
    assert(unit_testGetDestination());
    assert(unit_testSetSource());
    assert(unit_testSetDestination());
    assert(unit_testEquation());
}

bool UnitFlow::unit_testGetName() {
    Flow* flow = new UnitTestFlowStub ("TestGetName_Flow");
    assert(flow->getName() == "TestGetName_Flow");

    delete flow;

    std::cout << "FlowImpl::unit_getName() passed.\n";

    return true;
}

bool UnitFlow::unit_testGetSource() {
    System* source = new SystemImpl("TestGetSource_System", 100.0);
    Flow* flow = new UnitTestFlowStub ("TestGetSource_Flow", source, nullptr);
    assert(flow->getSource() == source);

    delete source;
    delete flow;

    std::cout << "FlowImpl::unit_getSource() passed.\n";

    return true;
}

bool UnitFlow::unit_testGetDestination() {
    System* destination = new SystemImpl("TestGetDestination_System", 100.0);
    Flow* flow = new UnitTestFlowStub ("TestGetDestination_Flow", nullptr, destination);

    assert(flow->getDestination() == destination);

    delete destination;
    delete flow;

    std::cout << "FlowImpl::unit_getDestination() passed.\n";

    return true;
}

bool UnitFlow::unit_testSetSource() {
    System* source = new SystemImpl("TestSetSource_System", 100.0);
    Flow* flow = new UnitTestFlowStub ("TestSetSource_Flow");
    flow->setSource(source);
    assert(flow->getSource() == source);

    delete source;
    delete flow;

    std::cout << "FlowImpl::unit_setSource() passed.\n";

    return true;
}

bool UnitFlow::unit_testSetDestination() {
    System* destination = new SystemImpl("TestSetDestination_System", 100.0);
    Flow* flow = new UnitTestFlowStub ("TestSetDestination_Flow");
    flow->setDestination(destination);
    assert(flow->getDestination() == destination);

    delete destination;
    delete flow;

    std::cout << "FlowImpl::unit_setDestination() passed.\n";

    return true;
}

bool UnitFlow::unit_testEquation() {
    Flow* flow = new UnitTestFlowStub ("TestEquation_Flow");
    assert(flow->equation() == 1.0);

    delete flow;

    std::cout << "FlowImpl::unit_equation() passed.\n";

    return true;
}
