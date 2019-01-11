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
    state<T> comeFrom;

public:
    state<T>(T state, double cost, State<T> comeFrom) {
        this.state = state;
    }

    bool Equals(State<T> s) {
        return state.equal(s.state);
    }

    void setCost(double cost) {
        this->cost = cost;
    }

    void setCameFrom(State<T> s) {
        this->comeFrom = s;
    }
};


#endif //SECONDMIILESTONE_STATE_H
