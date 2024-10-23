#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

vector<vector<int>> findDifference(vector<int> nums1, vector<int> nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());

    vector<int> result1;
    vector<int> result2;

    // Find elements in set1 that are not in set2
    for(int num : set1) {
        if(set2.find(num) == set2.end()) {
            result1.push_back(num);
        }
    }

    // Find elements in set2 that are not in set1
    for(int num : set2) {
        if(set1.find(num) == set1.end()) {
            result2.push_back(num);
        }
    }
    return {result1, result2};
}

int main() {
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};

    // Call findDifference with nums1 and nums2
    vector<vector<int>> result = findDifference(nums1, nums2);

    // Print elements in nums1 but not in nums2
    for(int i : result[0]) {
        cout << i << " ";
    }
    cout << endl;

    // Print elements in nums2 but not in nums1
    for(int i : result[1]) {
        cout << i << " ";
    }
    cout << endl;

}









