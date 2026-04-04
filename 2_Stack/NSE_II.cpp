#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums) {
    stack<int> st;
    vector<int> result(nums.size(), -1);

    // First pass: Calculate NSE from right to left
    for (int i = nums.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            result[i] = st.top();
        }
        st.push(nums[i]);
    }

    // Clear the stack for the second pass
    while (!st.empty()) {
        st.pop();
    }

    // Second pass: Handle circular nature, now iterate left to right
    for (int i = 0; i < nums.size(); i++) {
        while (!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }
        if (!st.empty() && result[i] == -1) {
            result[i] = st.top();  // Update result for -1 values
        }
        st.push(nums[i]);  // Push current element into stack again
    }

    return result;
}

int main() {
    vector<int> nums = {5, 4, 3, 2, 1};
    vector<int> result = nextGreaterElement(nums);

    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
