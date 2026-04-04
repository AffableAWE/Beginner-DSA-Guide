#include<iostream>
#include<stack>
#include<vector>
#include<string>

using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> operands;

    for(const string& token : tokens) {
        if(token == "+"|| token == "-"|| token == "*"||token == "/") {
            int secondOperand = operands.top();
            operands.pop();
            int firstOperand = operands.top();
            operands.pop();

            int result;
            if(token == "+") {
                result = firstOperand + secondOperand;
            }
            else if(token == "-") result = firstOperand - secondOperand;
            else if(token == "*") result = firstOperand * secondOperand;
            else if(token == "/") result = firstOperand / secondOperand;

            operands.push(result);
        }
        else {
            operands.push(stoi(token));
        }
    }
    return operands.top();
}
int main() {
    vector<string> tokens = {"1", "2", "+", "3", "*", "4", "-"};
    int result = evalRPN(tokens);
    cout<< "Result: " <<result << endl;
}
