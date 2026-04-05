/*
Title: LC-209 - Minimum Size Subarray Sum

Problem Statement:
Given an array of positive integers nums and a positive integer target,
return the minimal length of a subarray whose sum is greater than or equal
to target. If there is no such subarray, return 0 instead.

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2

Input: target = 4, nums = [1,4,4]
Output: 1

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

==================================================

Intuition:
1. Positive numbers is the key.
   That is why sliding window works cleanly here.

2. Goal is minimum valid window.
   So once sum >= target, start shrinking.

3. Shrink with while, not if.
   Keep shrinking until the window becomes invalid.

4. Formula to remember:
   grow until valid, shrink until invalid
*/

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(vector<int>& nums, int target) {
    int left = 0;
    int sum = 0;
    int minLen = INT_MAX;

    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];

        while (sum >= target) {
            minLen = min(minLen, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }

    if (minLen == INT_MAX) return 0;
    return minLen;
}

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    cout << minSubArrayLen(nums, target) << endl;

    return 0;
}
