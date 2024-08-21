#include "UnitModel.hpp"

#include "../../src/ModelImpl.hpp"
#include "../../src/SystemImpl.hpp"
#include "../../src/FlowImpl.hpp"

#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;

/**
 * @class UnitTestModelStub
 * @brief Subclass of FlowImpl for testing purposes.
 * @details UnitTestModelStub is a concrete subclass of FlowImpl designed specifically for testing. 
 * It implements the `equation` method from FlowImpl to return a constant value of 1.0. 
 * This class is used to facilitate unit testing of components that interact with Flow objects in a model by providing 
 * a predictable flow behavior without involving complex calculations.
 * @see FlowImpl
 * @see Flow
 * @see Model
 * @test This class is utilized in unit tests to verify the behavior of systems and models that work 
 * with Flow objects. The constant return value of 1.0 from the `equation` method allows testers to 
 * assess interactions and functionality within a controlled test environment.
 */
class UnitTestModelStub : public FlowImpl {
    public:
        /**
         * @brief Constructs a UnitTestModelStub object.
         * @param name The name of the flow (default is an empty string).
         * @param source Pointer to the source System (default is nullptr).
         * @param destination Pointer to the destination System (default is nullptr).
         */
        UnitTestModelStub(const std::string& name = "", System* source = nullptr, System* destination = nullptr)
            : FlowImpl(name, source, destination) {}

        /**
         * @brief Provides a constant value for the flow equation.
         * @details Overrides the pure virtual method `equation` from FlowImpl. 
         * This implementation returns a constant flow value of 1.0, which is useful 
         * for testing purposes. It simplifies the validation of interactions with Flow objects 
         * by providing a predictable result.
         * @return A constant value of 1.0.
         */
        double equation() const override { return 1.0; }
}; 

void UnitModel::runUnitTests() {
    assert(unit_testAddSystem());
    assert(unit_testAddFlow());
    assert(unit_testSetName());
    assert(unit_testGetName());
    assert(unit_testGetCurrentTime());
    assert(unit_testSetCurrentTime());
    assert(unit_testExecute());
}

bool UnitModel::unit_testGetName() {
    Model* model = new ModelImpl("TestGetName_Model");
    assert(model->getName() == "TestGetName_Model");

    delete model;

    std::cout << "Model::unit_getName() passed.\n";

    return true;
}

bool UnitModel::unit_testSetName() {
    Model* model = new ModelImpl();
    string modelName = "TestSetName_Model";
    model->setName(modelName);
    assert(model->getName() == modelName);

    delete model;

    std::cout << "Model::unit_setName() passed.\n";

    return true;
}

bool UnitModel::unit_testAddSystem() {
    ModelImpl* model = new ModelImpl("TestAddSystem_Model");
    System* system = new SystemImpl("TestAddSystem_System", 100.0);
    model->add(system);

    ModelImpl::SystemIterator iterator = std::find(model->systems.begin(), model->systems.end(), system);
    assert(iterator != model->systems.end());

    delete model;
    delete system;

    std::cout << "Model::unit_add(System*) passed.\n";

    return true;
}


bool UnitModel::unit_testAddFlow() {
    ModelImpl* model = new ModelImpl("TestAddFlow_Model");
    System* source = new SystemImpl("TestAddFlow_SourceSystem", 100.0);
    System* destination = new SystemImpl("TestAddFlow_DestinationSystem", 0.0);
    Flow* flow = new UnitTestModelStub("TestAddFlow_Flow", source, destination);
    model->add(flow);

    ModelImpl::FlowIterator it = std::find(model->flows.begin(), model->flows.end(), flow);
    assert(it != model->flows.end());

    delete model;
    delete source;
    delete destination;
    delete flow;

    std::cout << "Model::unit_add(Flow*) passed.\n";

    return true;
}

bool UnitModel::unit_testGetCurrentTime() {
    Model* model = new ModelImpl();
    assert(model->getCurrentTime() == 0);

    delete model;

    std::cout << "Model::unit_getCurrentTime() passed.\n";

    return true;
}

bool UnitModel::unit_testSetCurrentTime() {
    Model* model = new ModelImpl();
    model->setCurrentTime(10);
    assert(model->getCurrentTime() == 10);

    delete model;

    std::cout << "Model::unit_setCurrentTime() passed.\n";

    return true;
}

bool UnitModel::unit_testExecute() {
    Model* model = new ModelImpl();
    model->execute(0, 2, 1);
    assert(model->getCurrentTime() == 2);

    delete model;

    std::cout << "Model::unit_execute() passed.\n";

    return true;
}



