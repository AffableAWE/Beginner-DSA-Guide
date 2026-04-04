#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;

    for(int i = 0; i< n - 2; i++) {

        if(i>0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int left = i + 1;
        int right = n - 1;

        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if(sum == 0) {
                // Store the Triplet
                result.push_back({nums[i], nums[left], nums[right]});

                // skip the duplicates for left and right pointers
                while(left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                while(left < right && nums[right] == nums[right - 1]) {
                    right--;
                }

                // move both pointers after finding a valid triplet
                left++;
                right++;
            }
            else if(sum > 0) {
                right--;
            }
            else {
                left++;
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};  

    vector<vector<int>> result = threeSum(nums);

    cout << "Triplets that sum to zero are: " << endl;
    for (const auto& triplet : result) {
        cout << "[ ";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
