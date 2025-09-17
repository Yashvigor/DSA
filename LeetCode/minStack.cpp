#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> st;     // main stack
    stack<int> minSt;  // stack to keep track of minimums

public:
    MinStack() {
        // both stacks start empty
    }
    
    void push(int val) {
        st.push(val);
        // if minSt is empty OR new value is <= current minimum, push it to minSt
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }
    
    void pop() {
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
