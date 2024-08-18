#include "UnitModel.hpp"

/**
 * @class UnitTestModelFlowImpl
 * @brief Subclass of FlowImpl for testing purposes.
 * Implements the pure virtual method `equation` from FlowImpl.
 * @see FlowImpl
 * @test 
*/
class UnitTestModelFlowImpl : public FlowImpl {
public:
    UnitTestModelFlowImpl(const std::string& name = "", System* source = nullptr, System* destination = nullptr)
        : FlowImpl(name, source, destination) {}

    double equation() const override { return 1.0; }
}; 

void UnitModel::runTests() {
    testAddSystem();
    testAddFlow();
    testSetName();
    testGetName();
    testGetSystems();
    testGetFlows();
    testGetCurrentTime();
    testSetCurrentTime();
    testExecute();
}

void UnitModel::testGetName() {
    ModelImpl model("TestGetName_Model");
    assert(model.getName() == "TestGetName_Model");

    std::cout << "Model::getName() passed.\n";
}

void UnitModel::testSetName() {
    ModelImpl model;
    string modelName = "TestSetName_Model";
    model.setName(modelName);
    assert(model.getName() == modelName);

    std::cout << "Model::setName() passed.\n";
}

void UnitModel::testAddSystem() {
    ModelImpl model("TestAddSystem_Model");
    SystemImpl system("TestAddSystem_System", 100.0);
    model.add(&system);
    assert(model.getSystems().size() == 1);
    assert(model.getSystems()[0] == &system);

    std::cout << "Model::add(System*) passed.\n";
}

void UnitModel::testAddFlow() {
    ModelImpl model("TestAddFlow_Model");
    SystemImpl source("TestAddFlow_SourceSystem", 100.0);
    SystemImpl destination("TestAddFlow_DestinationSystem", 0.0);
    UnitTestModelFlowImpl flow("TestAddFlow_Flow", &source, &destination);
    model.add(&flow);

    assert(model.getFlows().size() == 1);
    assert(model.getFlows()[0] == &flow);

    std::cout << "Model::add(Flow*) passed.\n";
}

void UnitModel::testGetSystems() {
    ModelImpl model;
    SystemImpl system1("TestGetSystems_System1", 100.0);
    SystemImpl system2("TestGetSystems_System2", 200.0);
    model.add(&system1);
    model.add(&system2);
    vector<System*> systems = model.getSystems();

    assert(systems.size() == 2);
    assert(systems[0] == &system1);
    assert(systems[1] == &system2);

    std::cout << "Model::getSystems() passed.\n";
}

void UnitModel::testGetFlows() {
    ModelImpl model;
    SystemImpl source("TestGetFlows_SourceSystem", 100.0);
    SystemImpl destination("TestGetFlows_DestinationSystem", 0.0);
    UnitTestModelFlowImpl flow1("TestGetFlows_Flow1", &source, &destination);
    UnitTestModelFlowImpl flow2("TestGetFlows_Flow2", &source, &destination);
    model.add(&flow1);
    model.add(&flow2);
    vector<Flow*> flows = model.getFlows();

    assert(flows.size() == 2);
    assert(flows[0] == &flow1);
    assert(flows[1] == &flow2);

    std::cout << "Model::getFlows() passed.\n";
}

void UnitModel::testGetCurrentTime() {
    ModelImpl model;
    assert(model.getCurrentTime() == 0);

    std::cout << "Model::getCurrentTime() passed.\n";
}

void UnitModel::testSetCurrentTime() {
    ModelImpl model;
    model.setCurrentTime(10);
    assert(model.getCurrentTime() == 10);

    std::cout << "Model::setCurrentTime() passed.\n";
}

void UnitModel::testExecute() {
    ModelImpl model("TestExecute_Model");
    model.execute(0, 2, 1);
    assert(model.getCurrentTime() == 2);

    std::cout << "Model::execute() passed.\n";
}



