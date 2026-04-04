#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/**
 * Problem Statement:
 * Given an integer array nums of length n where all integers of nums are in the range [1, n].
 * Some elements appear once, and some appear twice. 
 * Return an array of all the integers that appear exactly twice.
 * 
 * Constraints:
 * - Solve in O(n) time and O(1) extra space (excluding the output array).
 * 
 * LeetCode Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/
 * 
 * Approach:
 * - Use the input array itself for marking and rearranging.
 * - First pass: Rearrange elements in their correct positions.
 * - Second pass: Collect elements that are not in their correct positions (duplicates).
 */

// Function to find duplicates using 0-based indexing
vector<int> findDuplicates(vector<int>& nums) {
    int n = nums.size();
    vector<int> result;
    result.reserve(n / 2); // Reserve space for worst-case duplicates

    // Rearrange elements to their correct positions
    for (int i = 0; i < n; i++) {
        while (nums[i] != nums[nums[i] - 1]) {
            swap(nums[i], nums[nums[i] - 1]); // Place nums[i] in its correct position
        }
    }

    // Collect duplicates
    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            result.push_back(nums[i]);
        }
    }

    return result;
}

/**
 * Alternate function to find duplicates using 1-based indexing
 * 
 * - Adjusted loop start and formula to handle 1-based indexing.
 */
vector<int> findDuplicates1Based(vector<int>& nums) {
    int n = nums.size();
    vector<int> result;
    result.reserve(n / 2); // Reserve space for worst-case duplicates

    // Rearrange elements to their correct positions
    for (int i = 1; i <= n; i++) {
        while (nums[i] != nums[nums[i]]) {
            swap(nums[i], nums[nums[i]]); // Place nums[i] in its correct position
        }
    }

    // Collect duplicates
    for (int i = 1; i <= n; i++) {
        if (nums[i] != i) {
            result.push_back(nums[i]);
        }
    }

    return result;
}

int main() {
    // Example input
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1, 3};

    // Find duplicates using 0-based indexing
    vector<int> result = findDuplicates(nums);

    // Print the result
    cout << "Duplicates: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}



