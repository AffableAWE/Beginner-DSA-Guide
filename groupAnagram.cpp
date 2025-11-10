#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramMap;
    for(string s : strs) {
        string sortedStr = s;
        sort(sortedStr.begin(), sortedStr.end());
        anagramMap[sortedStr].push_back(s);
    }
    vector<vector<string>> result;
    for(auto& pair : anagramMap) {
        result.push_back(pair.second);
    }
    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> groupedAnagrams = groupAnagrams(strs);
    for(const auto& group : groupedAnagrams) {
        for(const auto& word : group) {
            cout<< word << " ";
        }
        cout<<endl;
    }
}

