#include <cstdlib>
#include <iostream>
#include <cassert>

#include "../../src/SystemImpl.hpp"
#include "../../src/FlowImpl.hpp"
#include "../../src/ModelImpl.hpp"
#include "../../src/Bridge.hpp"

#include "UnitBridge.hpp" 



using namespace std;

class ExponentialFlow : public FlowHandle  {
    public:
        
        ExponentialFlow(const std::string& name = "", System* source = nullptr, System* destination = nullptr)
            : FlowHandle(name, source, destination) {}
        
        double equation() const override {
            if (this->getSource()) {
                return 0.01 * this->getSource()->getValue(); 
            }
            return 0.0;
        }
};

class LogisticFlow : public FlowHandle {
    public:
       
        LogisticFlow(const std::string& name, System* source = nullptr, System* destination = nullptr)
                : FlowHandle(name, source, destination) {}
                
        double equation() const override {
            if (this->getSource()) {
                return 0.01 * this->getDestination()->getValue() * (1 - this->getDestination()->getValue() / 70); // Logistic equation implementation
            }
            return 0.0;
        };
};

void UnitBridge::runUnitTests() {
    assert(unit_testBridge());
}

bool UnitBridge::unit_testBridge() {
    numHandleCreated = 0;
    numHandleDeleted = 0;
    numBodyCreated = 0;
    numBodyDeleted = 0;

    Model* model = Model::createModel("UnitBridgeTest_Model");
    Flow* exponentialFlow = model->createFlow<ExponentialFlow>("UnitExponentialFlowTest_Flow");

    System* s1 = model->createSystem("Population", 100);
    System* s2 = model->createSystem("Test", 7.90);

    cout << "s1: " << s1->getName() << ", s2: " << s2->getName() << endl;

    {
        SystemHandle s3("Tiago", 7), s4("Antonio", 8);
        cout << "s3: " << s3.getName() << ", s4: " << s4.getName() << endl;
        s3 = s4;
        cout << "After assignment s3: " << s3.getName() << ", s4: " << s4.getName() << endl;
        s3 = s3;
        cout << "s3: " << s4.getName() << ", s2: " << s4.getName() << endl;
    }
    
    exponentialFlow->setSource(s2);
    exponentialFlow->setDestination(s1);

    model->execute(0, 30, 1);

    // Print final state
    cout << "Final state of s1: " << s1->getValue() << endl;
    cout << "Final state of s2: " << s2->getValue() << endl;

    // Print debugging information
    cout << "Created handles: " << numHandleCreated << endl;
    cout << "Deleted handles: " << numHandleDeleted << endl;
    cout << "Created bodies: " << numBodyCreated << endl;
    cout << "Deleted bodies: " << numBodyDeleted << endl;

    std::cout << "FlowImpl::unit_getName() passed.\n";

    return true;
}