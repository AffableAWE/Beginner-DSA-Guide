#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> mpp;
    for(int i:nums) {
        mpp[i]++;
    }

    priority_queue<pair<int, int>> pq;
    for(auto i:mpp) {
        pq.push({i.second,i.first});
    }

    vector<int> result;
    for(int i = 0; i<k; i++) {
        result.push_back(pq.top().second);
        pq.pop();
    }
    return result;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> result = topKFrequent(nums, k);

    for(int num: result) {
        cout<< num << " ";
    }
    cout<<endl;
}
