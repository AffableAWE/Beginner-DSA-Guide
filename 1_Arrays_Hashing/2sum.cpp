#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> mpp;
    for(int i=0; i<nums.size(); i++) {
        int difference = target - nums[i];
        if(mpp.find(difference) != mpp.end()) {
            return{mpp[difference], i};
        }
        mpp[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 22;
    vector<int> result = twoSum(nums, target);

    if(!result.empty()) {
        cout<<result[0] << "," <<result[1] <<endl;
    }
    else {
        cout<< "No Solution Found "<<endl;
    }
}


