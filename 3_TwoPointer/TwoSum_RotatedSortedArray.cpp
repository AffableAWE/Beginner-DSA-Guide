#include<iostream>
#include<vector>

using namespace std;

int findpivot(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;

    while(low <= high) {
        int mid = low + (high - low)/2;

        if(nums[mid] > nums[high]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

vector<int> twosum(vector<int>& nums, int target) {
    int pivot = findpivot(nums);
    int left = pivot;
    int right = pivot - 1;

     // Adjust right to loop back to the end of the array when needed
    if (right < 0) right = nums.size() - 1;

    while (left != right) {  // We use != to ensure circular traversal
        int sum = nums[left] + nums[right];

        if (sum == target) {
            return {left + 1, right + 1};  // Return 1-based indices
        } else if (sum < target) {
            left = (left + 1) % nums.size();  // Move left forward circularly
        } else {
            right = (right - 1 + nums.size()) % nums.size();  // Move right backward circularly
        }
    }
    return {};
}

int main() {
    vector<int> nums = {11, 15, 2, 7};
    int target = 9;

    vector<int> result;

    result = twosum(nums, target);
    for(int i : result) {
        cout<< i << " ";
    }
    cout<<endl;
}

