#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> countMap;
    int maxLength = 0;
    int count = 0;

    countMap[0] = -1;

    for(int i = 0; i < nums.size(); i++) {
        count += (nums[i] == 1) ? 1 : -1;
        // Check if this count  has been seen before
        if(countMap.find(count) != countMap.end()) {
            // Calculating the length of the sub-array
            int length = i - countMap[count];
            maxLength = max(maxLength, length);
        }

        else {
            countMap[count] = i;
        }
    }
    return maxLength;
}

int main() {
    vector<int> nums = {0, 1, 0, 1, 1, 0};
    int result = findMaxLength(nums);

    cout<< result << endl;
}

