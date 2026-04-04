#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int maxArea(vector<int>& heights) {
    int n = heights.size();
    int left = 0;
    int right = n - 1;
    int maxxArea = 0;

    while(left < right) {
        int area = min(heights[left], heights[right]) * (right - left);
        
        maxxArea = max(maxxArea, area);

        if(heights[right] <= heights[left]) {
            right--;
        }
        else {
            left++;
        }
    }
    return maxxArea;
}

int main() {
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int result = maxArea(heights);

    cout<< "Maximum Water that can be contained is: " << result << endl;
    return 0;
}

