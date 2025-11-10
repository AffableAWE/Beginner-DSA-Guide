#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem Statement:
 * Given an integer array nums of length n where all integers of nums are in the range [1, n].
 * Some elements may appear once, some may appear twice, and some may appear more than twice.
 * Return an array of all the integers that appear more than twice.
 * 
 * Constraints:
 * - Solve in O(n) time and O(1) extra space (excluding the output array).
 * - You are allowed to modify the input array in place.
 * 
 * Approach:
 * 1. Rearrange the input array such that each element is placed at its correct index (nums[i] == i + 1).
 * 2. Collect misplaced elements (duplicates) into a result vector.
 * 3. Sort the result vector.
 * 4. Use a sliding window (or two pointers) to filter and collect elements that appear more than twice.
 */

vector<int> findDuplicates(vector<int>& nums) {
    int n = nums.size();
    vector<int> result;
    result.reserve(n / 2); // Reserve space for worst-case duplicates

    // Step 1: Rearrange the array
    for (int i = 0; i < n; i++) {
        while (nums[i] != nums[nums[i] - 1]) {
            swap(nums[i], nums[nums[i] - 1]); // Place nums[i] in its correct position
        }
    }

    // Step 2: Collect misplaced elements (duplicates)
    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            result.push_back(nums[i]);
        }
    }

    // Step 3: Sort the duplicates
    sort(result.begin(), result.end());

    // Step 4: Filter elements appearing more than twice
    vector<int> finalResult;
    int left = 0, right = 1;

    while (right < result.size()) {
        int count = 1;

        // Count occurrences of result[left]
        while (right < result.size() && result[left] == result[right]) {
            count++;
            right++;
        }

        // If the element appears more than twice, add to finalResult
        if (count > 2) {
            finalResult.push_back(result[left]);
        }

        // Move to the next group
        left = right;
        right = left + 1;
    }

    return finalResult;
}

int main() {
    // Example input
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 3, 1, 3};

    // Find elements appearing more than twice
    vector<int> result = findDuplicates(nums);

    // Print the result
    cout << "Elements appearing more than twice: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
