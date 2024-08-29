#include <stack>

class MinStack {
private:
    std::stack<int> Data;
    std::stack<int> Min;
public:
    MinStack() {
        
    }

    void push(int val) {
        Data.push(val);
        if (Min.empty() || val <= Min.top()) {
            Min.push(val);
        }
        else {
            Min.push(Min.top());
        }
    }

    void pop() {
        Data.pop();
        Min.pop();
    }

    int top() {
         return Data.top();
    }

    int getMin() {
        return Min.top();
    }
};