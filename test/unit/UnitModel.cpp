#include "UnitModel.hpp"

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
    assert(unit_testGetSystems());
    assert(unit_testGetFlows());
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
    Model* model = new ModelImpl("TestAddSystem_Model");
    System* system = new SystemImpl("TestAddSystem_System", 100.0);
    model->add(system);
    assert(model->getSystems().size() == 1);
    assert(model->getSystems()[0] == system);

    delete model;
    delete system;

    std::cout << "Model::unit_add(System*) passed.\n";

    return true;
}

bool UnitModel::unit_testAddFlow() {
    Model* model = new ModelImpl("TestAddFlow_Model");
    System* source = new SystemImpl("TestAddFlow_SourceSystem", 100.0);
    System* destination = new SystemImpl("TestAddFlow_DestinationSystem", 0.0);
    Flow* flow = new UnitTestModelStub("TestAddFlow_Flow", source, destination);
    model->add(flow);

    assert(model->getFlows().size() == 1);
    assert(model->getFlows()[0] == flow);

    delete model;
    delete source;
    delete destination;
    delete flow;

    std::cout << "Model::unit_add(Flow*) passed.\n";

    return true;
}

bool UnitModel::unit_testGetSystems() {
    Model* model = new ModelImpl();
    System* system1 = new SystemImpl("TestGetSystems_System1", 100.0);
    System* system2 = new SystemImpl("TestGetSystems_System2", 200.0);
    model->add(system1);
    model->add(system2);
    vector<System*> systems = model->getSystems();

    assert(systems.size() == 2);
    assert(systems[0] == system1);
    assert(systems[1] == system2);

    delete model;
    delete system1;
    delete system2;

    std::cout << "Model::unit_getSystems() passed.\n";

    return true;
}

bool UnitModel::unit_testGetFlows() {
    Model* model = new ModelImpl();
    System* source = new SystemImpl("TestGetFlows_SourceSystem", 100.0);
    System* destination = new SystemImpl("TestGetFlows_DestinationSystem", 0.0);
    Flow* flow1 = new UnitTestModelStub("TestGetFlows_Flow1", source, destination);
    Flow* flow2 = new UnitTestModelStub("TestGetFlows_Flow2", source, destination);
    model->add(flow1);
    model->add(flow2);
    vector<Flow*> flows = model->getFlows();

    assert(flows.size() == 2);
    assert(flows[0] == flow1);
    assert(flows[1] == flow2);

    delete model;
    delete source;
    delete destination;
    delete flow1;
    delete flow2;

    std::cout << "Model::unit_getFlows() passed.\n";

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



