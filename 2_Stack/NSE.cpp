#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> findNextGreaterElements(vector<int>& arr) {
    stack<int> st;
    vector<int> result(arr.size(), -1);

    for(int i = arr.size() - 1; i>=0; i--) {
        while(!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        if(!st.empty()) {
            result[i] = st.top();
        }

        st.push(arr[i]);
    }
    
   return result;
}

int main() {
    vector<int> arr = {2, 1, 4, 3};
    vector<int> result = findNextGreaterElements(arr);

    for(int i : result) {
        cout<< i << " " ;
    }
    cout<< endl;
}

