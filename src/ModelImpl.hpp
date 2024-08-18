#ifndef MODEL_IMPL_HPP
#define MODEL_IMPL_HPP

#include "Model.hpp"
#include "System.hpp"
#include "Flow.hpp"

#include <algorithm>

using std::vector;
using std::string;

using namespace std;

/**
 * @class ModelImpl
 * @brief Concrete implementation of the Model interface.
 * @see System 
 * @see Model
 * @see Flow
*/
class ModelImpl : public Model {
    friend class ModelTest;
    private:
        string name;                /**< Name of the model. */
        vector<System*> systems;   /**< Vector storing pointers to the systems within the model. */
        vector<Flow*> flows;      /**< Vector storing pointers to the flows within the model. */
        int currentTime;         /**< Current time in the simulation. */

        typedef vector<System*>::iterator SystemIterator;    /**< Typedef for an iterator for the systems vector. */
        typedef vector<Flow*>::iterator FlowIterator;       /**< Typedef for an iterator for the flows vector.*/
    public:

        /**
         * @brief Default constructor for the Model class.
         * @details Initializes a Model object with no systems or flows.
        */
        ModelImpl();

        /**
         * @brief Constructs a model with a specified name.
         * @details Initializes the model with the given name and no systems or flows.
         * @param name The name of the model.
        */
        ModelImpl(const string& name);

        /**
         * @brief Copy constructor for the Model class.
         * @details Initializes a Model object as a copy of another Model object.
         * @param other Model object to copy.
        */
        ModelImpl(const ModelImpl& other);

        /**
         * @brief Assignment operator for the Model class.
         * @details Assigns one Model object to another.
         * @param other Another instance of Model to be assigned.
         * @return A reference to this Model instance.
         */
        ModelImpl& operator=(const ModelImpl& other);

        virtual ~ModelImpl();

        void add(System* system) override;
        void add(Flow* flow) override;

        void setName(const string& modelName) override;
        string getName() const override;

        vector<System*> getSystems() const override;
        vector<Flow*> getFlows() const override;

        int getCurrentTime() const override;
        void setCurrentTime(int time) override;

        void execute(int startTime, int endTime, int timeStep) override;
};

#endif
