#include "funcionalTests.hpp"

#include <iostream>
#include <cassert>
#include <string>
#include <cmath>

//ExponentialFlow equation Implementation.
double ExponentialFlow::equation() const {
    if (source != nullptr) {
        return 0.01 * source->getValue();
    }
    return 0.0;
}

//LogisticFlow equation Implementation.
double LogisticFlow::equation() const {
    if (source != nullptr) {
        return 0.01 * destination->getValue() * (1 - destination->getValue() / 70);
    }
    return 0.0;
}

//Tests Implementation.
void exponentialFlow() {
    Model* model = Model::createModel("Exponential Flow");

    System* population1 = model->createSystem("pop1", 100);
    System* population2 = model->createSystem("pop2", 0);

    ExponentialFlow* exponentialFlow = model->createFlow<ExponentialFlow>("exponential", population1, population2);

    model->execute(0, 100, 1);

    assert(fabs((round((population1->getValue() * 10000)) - 10000 * 36.6032)) < 0.0001);
    assert(fabs((round((population2->getValue() * 10000)) - 10000 * 63.3968)) < 0.0001);

    Model::deleteModel();

    std::cout << "Exponential Flow test Passed!" << std::endl;
}

void logisticFlow() {
    Model* model = Model::createModel("Logistic Flow");

    System* p1 = model->createSystem("p1", 100);
    System* p2 = model->createSystem("p2", 10);

    LogisticFlow* logisticFlow = model->createFlow<LogisticFlow>("logistic", p1, p2);

    model->execute(0, 100, 1);

    assert(fabs((round((p1->getValue() * 10000)) - 10000 * 88.2167)) < 0.0001);
    assert(fabs((round((p2->getValue() * 10000)) - 10000 * 21.7833)) < 0.0001);

    Model::deleteModel();

    std::cout << "Logistic Flow Test Passed!" << std::endl;
}

void complexFlow() {
    Model* model = Model::createModel("Complex Flow");
    
    // Criação dos sistemas
    System* q1 = model->createSystem("Q1", 100);
    System* q2 = model->createSystem("Q2", 0);
    System* q3 = model->createSystem("Q3", 100);
    System* q4 = model->createSystem("Q4", 0);
    System* q5 = model->createSystem("Q5", 0);
    
    // Criação dos fluxos
    Flow* f = model->createFlow<ExponentialFlow>("f", q1, q2);
    Flow* g = model->createFlow<ExponentialFlow>("g", q1, q3);
    Flow* r = model->createFlow<ExponentialFlow>("r", q2, q5);
    Flow* t = model->createFlow<ExponentialFlow>("t", q2, q3);
    Flow* u = model->createFlow<ExponentialFlow>("u", q3, q4);
    Flow* v = model->createFlow<ExponentialFlow>("v", q4, q1);

    model->execute(0, 100, 1);

    assert(fabs((round((q1->getValue() * 10000)) - 10000 * 31.8513)) < 0.0001);
    assert(fabs((round((q2->getValue() * 10000)) - 10000 * 18.4003)) < 0.0001);
    assert(fabs((round((q3->getValue() * 10000)) - 10000 * 77.1143)) < 0.0001);
    assert(fabs((round((q4->getValue() * 10000)) - 10000 * 56.1728)) < 0.0001);
    assert(fabs((round((q5->getValue() * 10000)) - 10000 * 16.4612)) < 0.0001);

    Model::deleteModel();

    std::cout << "Complex Flow Test Passed!" << std::endl;
}
