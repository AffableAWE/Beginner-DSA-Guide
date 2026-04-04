#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// Brute Force Approach ~ Nested loops
 int maxSubArraySum(vector<int>& nums, int k) {
     int n = nums.size();
     int maxSum = 0;
 
     for(int i = 0; i<= n-k; i++) {
         int sum = 0;
         for(int j = i; j<=n-k; j++) {
             sum += nums[j];
             maxSum = max(maxSum, sum);
         }
     }
     return maxSum;
 }

// Optimal Approach ~ Using sliding window 
int maxSubArraySum(vector<int>& nums, int k) {
    int windowSum = 0;
    int maxSum = 0;

    // Calculating the sum for first k elements
    for(int i = 0; i<k; i++) {
        windowSum += nums[i];
    }
    maxSum = windowSum;

    // Sliding the window over the rest of the array
    for(int i = k; i<nums.size(); i++) {
        // Subtracting the leftmost element from the sum and adding the sum of the upcoming element
        windowSum += nums[i] - nums[i - k];
        maxSum = max(windowSum, maxSum);
    }
    return maxSum;
}

int main() {
    vector<int> nums = {2, 1, 5, 1, 3, 2};
    int k = 3;

    int result = maxSubArraySum(nums, k);

    cout<< result << endl;
}


