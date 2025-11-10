#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

int longestConsecutiveSeq(vector<int>& nums) {
    unordered_set<int> set(nums.begin(), nums.end());
    
    int maxCount = 0;
    for(int num : set) {
        if(set.find(num - 1) == set.end()) {
            int currentNum = num;
            int currentStreak = 1;

            while(set.find(currentNum + 1) != set.end()) {
                currentNum++;
                currentStreak++;
            }
            maxCount = max(maxCount, currentStreak);
        }
    }
    return maxCount;
}

int main() {
    vector<int> nums = {2, 20, 4, 10, 3, 4, 5};
    int result = longestConsecutiveSeq(nums);

    cout<< "Longest Consecutive Length : " << result << endl;
}
