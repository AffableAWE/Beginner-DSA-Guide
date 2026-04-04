#include<iostream> 
#include<vector> 
#include<algorithm> 

using namespace std;  

int trap(vector<int>& heights) { 
    int n = heights.size(); 
    int left = 0; 
    int right = n - 1; 
    int leftMax = heights[left]; 
    int rightMax = heights[right]; 
    int result = 0; 

    while(left <= right) { 
        if(leftMax < rightMax) { // Water is trapped based on left max height 
             if(heights[left] < leftMax) {
                result += leftMax - heights[left];
            }
            else {
                leftMax = heights[left];
            }
            left++;
        }
        else {
            // Water is trapped based on right max height
            if(heights[right] < rightMax) {
                result += rightMax - heights[right]; // Water tapped at the right
            }
            else {
                rightMax = heights[right];
            }
            right--;
        }
    }
    return result;
}

int main() {
    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result = trap(heights);

    cout<< result << endl;
    return 0;
}
    
                                                     






