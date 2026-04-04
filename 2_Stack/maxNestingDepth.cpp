#include<iostream>
#include<string>

using namespace std;

int maxDepth(string s) {
    int currentCount = 0;
    int maxCount = 0;

    for(char c : s) {
        if(c == '(') {
            currentCount++;
            if(maxCount < currentCount) {
                maxCount = currentCount;
            }
        }
        else if(c == ')') {
            currentCount--;
        }
    }
    return maxCount;
}

int main() {
    string s = "(1+(2*3)+((8)/4))+1";
    int result = maxDepth(s);

    cout<< result << endl;
}


