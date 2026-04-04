#include<vector>
#include<iostream>

using namespace std;
    void reorganize(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]); 
            }
    }
}
    int firstMissingPositive(vector<int>& nums) {
        reorganize(nums); // Reorganise the array
            for(int i = 0; i<nums.size(); i++) {
                if(nums[i] != i + 1) {
                return i + 1;
            }
    }
        return nums.size() + 1;    

}
    int main() {
        vector<int> nums = {3, 4, -1, 1};
        int result = firstMissingPositive(nums);
        cout<< result << endl;
}
