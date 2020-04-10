#include<iostream>
#include<stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> value;
    stack<int> min;

    MinStack() {
    }

    void push(int x) {
        value.push(x);
        if (min.size() == 0) {
            min.push(x);
        } else {
            min.push(x < min.top() ? x : min.top());
        }
    }

    void pop() {
        value.pop();
        min.pop();
    }

    int top() {
        return value.top();
    }

    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


int main() {
    MinStack ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.top() << endl;
    cout << ms.getMin() << endl;
    return 0;
}
