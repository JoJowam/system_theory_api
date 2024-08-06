#include "funcionalTests.hpp"

void exponentialFlow() {
    std::cout << "Starting Exponential Flow Test..." << std::endl;
    //System build
    System* population1 = new System("pop1", 100);
    System* population2 = new System("pop2", 0);

    //Flow build
    ExponentialFlow* exponentialFlow = new ExponentialFlow("exponential", population1, population2);

    //Model build and assignments
    Model* model = new Model();
    model->add(population1);
    model->add(population2);
    model->add(exponentialFlow);

    //Model execution
    model->execute(1, 100, 1);

    //Asserts
    assert(fabs((round((population1->getValue() * 10000)) - 10000 * 36.6032)) < 0.0001);
    assert(fabs((round((population2->getValue() * 10000)) - 10000 * 63.3968)) < 0.0001);

    std::cout << "Exponential Flow Test Completed Successfully..." << std::endl;
}

void logisticFlow() {
    std::cout << "Starting Logistic Flow Test..." << std::endl;
    //System build
    System* p1 = new System("p1", 100);
    System* p2 = new System("p2", 10);

    //Flow build
    LogisticFlow* logisticFlow = new LogisticFlow("logistic", p1, p2);

    //Model build and assignments
    Model* model = new Model();
    model->add(p1);
    model->add(p2);
    model->add(logisticFlow);

    //Model execution
    model->execute(1, 100, 1);

    assert(fabs((round((p1->getValue() * 10000)) - 10000 * 88.2167)) < 0.0001);
    assert(fabs((round((p2->getValue() * 10000)) - 10000 * 21.7833)) < 0.0001);

    std::cout << "Logistic Flow Test Completed Successfully." << std::endl;
}

void complexFlow() {
    std::cout << "Starting Complex Flow Test..." << std::endl;
    //System build
    System* q1 = new System("Q1", 100);
    System* q2 = new System("Q2", 0);
    System* q3 = new System("Q3", 100);
    System* q4 = new System("Q4", 0);
    System* q5 = new System("Q5", 0);

    //Flow build
    ExponentialFlow* f = new ExponentialFlow("f", q1, q2);
    ExponentialFlow* g = new ExponentialFlow("g", q1, q3);
    ExponentialFlow* r = new ExponentialFlow("r", q2, q5);
    ExponentialFlow* t = new ExponentialFlow("t", q2, q3);
    ExponentialFlow* u = new ExponentialFlow("u", q3, q4);
    ExponentialFlow* v = new ExponentialFlow("v", q4, q1);

    //Model build and assignments
    Model* model = new Model();
    model->add(q1);
    model->add(q2);
    model->add(q3);
    model->add(q4);
    model->add(q5);
    model->add(f);
    model->add(g);
    model->add(r);
    model->add(t);
    model->add(u);
    model->add(v);

    //Model execution
    model->execute(1, 100, 1);

    assert(fabs((round((q1->getValue() * 10000)) - 10000 * 31.8513)) < 0.0001);
    assert(fabs((round((q2->getValue() * 10000)) - 10000 * 18.4003)) < 0.0001);
    assert(fabs((round((q3->getValue() * 10000)) - 10000 * 77.1143)) < 0.0001);
    assert(fabs((round((q4->getValue() * 10000)) - 10000 * 56.1728)) < 0.0001);
    assert(fabs((round((q5->getValue() * 10000)) - 10000 * 16.4612)) < 0.0001);

    std::cout << "Complex Flow Test Completed Successfully." << std::endl;
}