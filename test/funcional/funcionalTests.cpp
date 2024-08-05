#include "funcionalTests.hpp"

void exponentialFlow() {
    //System build
    System* population1 = new System("pop1", 100);
    System* population2 = new System("pop2", 0);

    //Flow build
    ExponentialFlow* exponentialFlow = new ExponentialFlow("exponential", population1, population2);

    //Model build and atribuitions
    Model* model = new Model();
    model->add(population1);
    model->add(population2);
    model->add(exponentialFlow);

    //Model execution
    model->execute(1, 100, 1);

    assert(fabs((round((population1->getValue()*10000)) - 10000* 36.6032)) < 0.0001);
    assert(fabs((round((population2->getValue()*10000)) - 10000* 63.3968)) < 0.0001);

    delete model;
    delete population1;
    delete population2;
    delete exponentialFlow;
}

void logisticFlow(){
    //System build
    System* p1 = new System("p1", 100);
    System* p2 = new System("p2", 10);

    //Flow build
    LogisticFlow* logisticFlow = new LogisticFlow("logistica", p1, p2);

    //Model build and atribuitions
    Model* model = new Model();
    model->add(p1);
    model->add(p2);
    model->add(logisticFlow);

    //Model execution
    model->execute(1, 100, 1);

    assert(fabs((round((p1->getValue()*10000)) - 10000* 88.2167)) < 0.0001);
    assert(fabs((round((p2->getValue()*10000)) - 10000* 21.7833)) < 0.0001);

    delete model;
    delete p1;
    delete p2;
    delete logisticFlow;
}

void complexFlow(){

}