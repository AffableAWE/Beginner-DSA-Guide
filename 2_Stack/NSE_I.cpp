#include<iostream>
#include<stack>
#include<unordered_map>
#include<vector>

using namespace std;

vector<int> nextGreaterElement(vector<int>& num1, vector<int>& num2) {
    stack<int> st;
    vector<int> result(num2.size(), -1);

    // Calculating NSE for num2
    for (int i = num2.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= num2[i]) {
            st.pop();
        }
        if (!st.empty()) {
            result[i] = st.top();
        }
        st.push(num2[i]);
    }

    // Mapping all NSEs in the unordered map
    unordered_map<int, int> nseMap;
    for (int i = 0; i < num2.size(); i++) {
        nseMap[num2[i]] = result[i];
    }

    // Iterating in num1 and pushing the NSE values
    vector<int> resultNum;
    for (int i = 0; i < num1.size(); i++) {
        resultNum.push_back(nseMap[num1[i]]);
    }

    return resultNum;
}

int main() {
    vector<int> num1 = {4, 1, 2};
    vector<int> num2 = {1, 3, 4, 2};

    vector<int> result = nextGreaterElement(num1, num2);

    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
