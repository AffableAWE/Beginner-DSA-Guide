#include<iostream>
#include<unordered_map>
#include<stack>

using namespace std;

bool isValid(string s) {
    unordered_map<char, char> bracketMap {
        {')' , '('},
        {'}' , '{'},
        {']' , '['}
    };

    stack<char> stack;
    for(char c : s) {
        if(bracketMap.find(c) != bracketMap.end()) { // if its a closing bracket!
            if(!stack.empty() && stack.top() == bracketMap[c]) { // if top(stack) matches the
                                                                 // corresponding opening bracket
                stack.pop();
            }
            else {
                return false;
            }
        }
        else {
            stack.push(c); // its an opening bracket, push onto the stack
        }
    }
    return stack.empty(); // if the stack is empty all brackets were matched
}

int main() {
    string s = "{[()]}";
    if(isValid(s)) {
        cout<< "Valid Parentheses " << endl;
    }
    else {
        cout<< "Invalid Parentheses " << endl;
    }
}

   
