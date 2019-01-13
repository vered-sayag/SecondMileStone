//
// Created by davidregev on 10/01/19.
//

#ifndef SECONDMIILESTONE_STATE_H
#define SECONDMIILESTONE_STATE_H


using namespace std;

template <class T>
class State {
    T state;
    double cost;
    State<T> comeFrom;

public:
    State<T>(T state, double cost, State<T> comeFrom) {
        this->state = state;
    }

    bool operator==(State<T> s) {
        return (getState() == s.getState());
    }

    T getState() const {
        return state;
    }

    double getCost() const {
        return cost;
    }

    void setCost(double cost) {
        this->cost = cost;
    }

    void setCameFrom(State<T> s) {
        this->comeFrom = s;
    }
};


#endif //SECONDMIILESTONE_STATE_H
