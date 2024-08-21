#ifndef MODEL_IMPL_HPP
#define MODEL_IMPL_HPP

#include "Model.hpp"
#include "System.hpp"
#include "Flow.hpp"

using std::vector;
using std::string;

using namespace std;

/**
 * @class ModelImpl
 * @brief Concrete implementation of the Model interface.
 * @details ModelImpl provides a concrete implementation of the Model interface, managing the interactions 
 * between systems and flows within a simulation. It tracks the current time of the simulation and allows 
 * for the execution of the model over a specified time range.
 * 
 * @see System 
 * @see Flow
 * @see Model
 * @warning Ensure all systems and flows are properly configured before executing the model.
 * @date 2024-08-18
 * @version 0.0.1
 */
class ModelImpl : public Model {
    friend class UnitModel;          /**< Friend class for unit testing. */

    private:
        string name;                 /**< Name of the model.*/
        vector<System*> systems;     /**< Vector storing pointers to the systems within the model.*/
        vector<Flow*> flows;         /**< Vector storing pointers to the flows within the model.*/
        int currentTime;             /**< Current time in the simulation.*/

        typedef vector<System*>::iterator SystemIterator;    /**< Typedef for an iterator for the systems vector. */
        typedef vector<Flow*>::iterator FlowIterator;        /**< Typedef for an iterator for the flows vector. */

    public:

        /**
         * @brief Default constructor for the ModelImpl class.
         * @details Initializes a ModelImpl object with no systems or flows.
         * 
         * @note This constructor allows for the creation of a ModelImpl instance that can be configured later.
         * 
         * @code
         * Model* model = new ModelImpl();
         * model->setName("Example Model");
         * @endcode
         */
        ModelImpl();

        /**
         * @brief Constructs a ModelImpl with a specified name.
         * @details Initializes the model with the given name and no systems or flows.
         * @param name The name of the model.
         * 
         * @note The name helps in identifying the model within a larger simulation framework.
         * 
         * @code
         * Model* model = new ModelImpl("Example Model");
         * @endcode
         */
        ModelImpl(const string& name);

        /**
         * @brief Copy constructor for the ModelImpl class.
         * @details Initializes a ModelImpl object as a copy of another ModelImpl object, duplicating its systems and flows.
         * @param other ModelImpl object to copy.
         * 
         * @note The copy constructor ensures that a shallow copy of the ModelImpl object is made.
         * 
         * @code
         * Model* originalModel = new ModelImpl("Original Model");
         * Model* copiedModel = new ModelImpl(*originalModel);
         * @endcode
         */
        ModelImpl(const ModelImpl& other);

        /**
         * @brief Assignment operator for the ModelImpl class.
         * @details Assigns one ModelImpl object to another, ensuring proper handling of dynamic memory and object state.
         * @param other Another instance of ModelImpl to be assigned.
         * @return A reference to this ModelImpl instance.
         * 
         * @note The assignment operator should handle self-assignment and ensure that all resources are properly managed.
         * 
         * @code
         * Model* model1 = new ModelImpl("Model 1");
         * Model* model2 = new ModelImpl("Model 2");
         * model2 = model1;
         * @endcode
         */
        ModelImpl& operator=(const ModelImpl& other);

        /**
         * @brief Destructor for the ModelImpl class.
         * @details Ensures that resources allocated by the ModelImpl instance are properly cleaned up.
         * 
         * @note The destructor must ensure that any dynamic memory or resources are released to avoid memory leaks.
         */
        virtual ~ModelImpl();

        void add(System* system) override;
        void add(Flow* flow) override;

        void setName(const string& modelName) override;
        string getName() const override;

        int getCurrentTime() const override;
        void setCurrentTime(int time) override;

        void execute(int startTime, int endTime, int timeStep) override;
};

#endif