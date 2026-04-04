#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int maxArea = 0;
    stack<int> st;

    for(int i = 0; i<=n; i++) {

        // Use 0 height for the sentinel to ensure, all bars are processed  
        int currentHeight = (i < n) ? heights[i] : 0 ;

        while(!st.empty() && currentHeight <= heights[st.top()]) {
            int top = st.top();
            st.pop();

        // Determine Width
        int width = st.empty() ? i : i - st.top() - 1;

        // Calulate Area
        int area = heights[top]*width;

        // Update the max area
        maxArea = max(maxArea, area);

        }

        st.push(i);
    }
    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int result = largestRectangleArea(heights);
    cout<< "Area of the Largest Rectangle: " << result << endl;
}

