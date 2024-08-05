#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>
#include <string>

using std::string;

class flow;

class System {
    private:
        string name;
        double value;

    public:
        System();
        System(const string& name);
        System(const string& name, double value);
        System(const System& other);
        System& operator=(const System& other);
        virtual ~System();

        const string getName() const;
        double getValue() const;

        void setValue(double value);
};

#endif