#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

vector<int> topK_UsingMinHeap(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for(auto& i : nums) mp[i]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    for(auto& entry : mp) {
        minHeap.push({entry.second, entry.first});
        if(minHeap.size() > k) minHeap.pop();
    }

    vector<int> result;
    while(!minHeap.empty()) {
//         result.push_back(minHeap.top().second);
        result.insert(result.begin(), minHeap.top().second);
        minHeap.pop();
    }
    return result;
}
int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> result = topK_UsingMinHeap(nums, k);

    for(int num: result) {
        cout<< num << " ";
    }
    cout<<endl;
}




