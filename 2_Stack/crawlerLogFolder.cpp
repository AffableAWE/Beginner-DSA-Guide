#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

// optimised Solution with TC - O(n) & SC - O(1)
int minOperations(vector<string>& logs) {
    int dept = 0;

    for(string &s : logs) {
        if(s == "../") {
            if(dept > 0) dept --;
        }
        else if(s == "./") {
            // We gonna do nothing here!!!
        }
        else {
            dept++;
        }
    }
    return dept;


// Solution using stack with TC - O(n) & SC - O(n)
//     stack<string> st;
// 
//         for(string &s : logs) {
//             if(s == "../")
//                 if(!st.empty()) st.pop();
//                 //If stack is empty, we're at main folder; do nothing
//             else if(s == "./") {
//                 // We do nothing 
//             }
//             else {
//                 // It's a folder name; push onto the stack
//                 st.push();
//             }
//         }
//         return st.size();
    
}

int main() {
    vector<string> logs = {"d1/", "d2/", "../", "d21/", "./"};
    cout<< minOperations(logs) << endl;
}

