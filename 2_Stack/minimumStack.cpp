#include<iostream>
#include<stack>

using namespace std;

class MinStack {
public:
    stack<int> mainStack;
    stack<int> minStack;

    MinStack() {

    }

    void push(int val) {
        mainStack.push(val);
        if(minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if(!mainStack.empty()) {
            int topElement = mainStack.top();
            mainStack.pop();
            if(topElement == minStack.top()) {
                minStack.pop();
            }
        }
    }

    int top() {
        return mainStack.empty() ? -1 : mainStack.top();

    }

    int getMin() {
        return minStack.empty() ? -1 : minStack.top();
    }
};

int main() {
    MinStack minStack;

    minStack.push(1);
    minStack.push(2);
    minStack.push(0);

    cout << "Minimum value: " << minStack.getMin() << endl; // Should return 0
    minStack.pop();
    cout << "Top value: " << minStack.top() << endl; // Should return 2
    cout << "Minimum value: " << minStack.getMin() << endl; // Should return 1

    return 0;
}
