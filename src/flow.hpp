#ifndef FLOW_HPP
#define FLOW_HPP

#include <string>

class System;

using std::string;

class Flow{
    protected:
        string name;
        System* source;
        System* destination;

    public:
        Flow();
        Flow(const string& name, System* source = nullptr, System* destination = nullptr);
        Flow(const string& name);
        Flow(const Flow& other);
        Flow& operator=(const Flow& other);
        virtual ~Flow();

        const string& getName() const;
        System* getSource() const;
        System* getDestination() const;
        void setSource(System* source);
        void setDestination(System* destination);

        virtual double equation() const = 0;
};

#endif