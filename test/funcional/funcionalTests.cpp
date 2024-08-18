#include "funcionalTests.hpp"

//ExponentialFlow Implementation.
ExponentialFlow::ExponentialFlow() 
    : FlowImpl() {}

ExponentialFlow::ExponentialFlow(const std::string& name, System* source, System* destination) 
    : FlowImpl(name, source, destination) {}

ExponentialFlow::ExponentialFlow(const ExponentialFlow& other) 
    : FlowImpl(other) {}

ExponentialFlow& ExponentialFlow::operator=(const ExponentialFlow& other) {
    if (this != &other) {
        FlowImpl::operator=(other);
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

//LogisticFlow Implementation.
LogisticFlow::LogisticFlow() 
    : FlowImpl() {}

LogisticFlow::LogisticFlow(const std::string& name, System* source, System* destination) 
    : FlowImpl(name, source, destination) {}

LogisticFlow::LogisticFlow(const LogisticFlow& other) 
    : FlowImpl(other) {}

LogisticFlow& LogisticFlow::operator=(const LogisticFlow& other) {
    if (this != &other) {
        FlowImpl::operator=(other);
    }
    return *this;
}

LogisticFlow::~LogisticFlow() {}

double LogisticFlow::equation() const {
    if (source != nullptr) {
        return 0.01 * destination->getValue() * (1 - destination->getValue() / 70);
    }
    return 0.0;
}

//Tests Implementation.
void exponentialFlow() {
    std::cout << "Starting Exponential Flow Test..." << std::endl;

    System* population1 = new SystemImpl("pop1", 100);
    System* population2 = new SystemImpl("pop2", 0);

    ExponentialFlow* exponentialFlow = new ExponentialFlow("exponential", population1, population2);

    Model* model = new ModelImpl();
    model->add(population1);
    model->add(population2);
    model->add(exponentialFlow);

    model->execute(0, 100, 1);

    assert(fabs((round((population1->getValue() * 10000)) - 10000 * 36.6032)) < 0.0001);
    assert(fabs((round((population2->getValue() * 10000)) - 10000 * 63.3968)) < 0.0001);

    std::cout << "Exponential Flow Test Completed Successfully..." << std::endl;
}

void logisticFlow() {
    std::cout << "Starting Logistic Flow Test..." << std::endl;

    System* p1 = new SystemImpl("p1", 100);
    System* p2 = new SystemImpl("p2", 10);

    LogisticFlow* logisticFlow = new LogisticFlow("logistic", p1, p2);

    Model* model = new ModelImpl();
    model->add(p1);
    model->add(p2);
    model->add(logisticFlow);

    model->execute(0, 100, 1);

    assert(fabs((round((p1->getValue() * 10000)) - 10000 * 88.2167)) < 0.0001);
    assert(fabs((round((p2->getValue() * 10000)) - 10000 * 21.7833)) < 0.0001);

    std::cout << "Logistic Flow Test Completed Successfully." << std::endl;
}

void complexFlow() {
    std::cout << "Starting Complex Flow Test..." << std::endl;

    System* q1 = new SystemImpl("Q1", 100);
    System* q2 = new SystemImpl("Q2", 0);
    System* q3 = new SystemImpl("Q3", 100);
    System* q4 = new SystemImpl("Q4", 0);
    System* q5 = new SystemImpl("Q5", 0);

    ExponentialFlow* f = new ExponentialFlow("f", q1, q2);
    ExponentialFlow* g = new ExponentialFlow("g", q1, q3);
    ExponentialFlow* r = new ExponentialFlow("r", q2, q5);
    ExponentialFlow* t = new ExponentialFlow("t", q2, q3);
    ExponentialFlow* u = new ExponentialFlow("u", q3, q4);
    ExponentialFlow* v = new ExponentialFlow("v", q4, q1);

    Model* model = new ModelImpl();
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

    model->execute(0, 100, 1);

    assert(fabs((round((q1->getValue() * 10000)) - 10000 * 31.8513)) < 0.0001);
    assert(fabs((round((q2->getValue() * 10000)) - 10000 * 18.4003)) < 0.0001);
    assert(fabs((round((q3->getValue() * 10000)) - 10000 * 77.1143)) < 0.0001);
    assert(fabs((round((q4->getValue() * 10000)) - 10000 * 56.1728)) < 0.0001);
    assert(fabs((round((q5->getValue() * 10000)) - 10000 * 16.4612)) < 0.0001);

    std::cout << "Complex Flow Test Completed Successfully." << std::endl;
}
