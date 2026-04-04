#include<iostream>
#include<unordered_set>
#include<string>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> charSet;
    int left = 0;
    int right = 0;
    int maxCount = 0;

    while(right < s.length()) {
        // If the character is not in the set, add it and move the right pointer
        if(charSet.find(s[right]) == charSet.end()) {
                charSet.insert(s[right]);
                right++;
                maxCount = max(maxCount, right - left);

        }
        else { 
            // If the character is duplicate, remove the leftmost char and move the right pointer
            charSet.erase(s[left]);
            left++;
        }
    }
    return maxCount;
}

int main() {
    string s = "abcabcbb";
    int result = lengthOfLongestSubstring(s);

    cout<< result << endl;
    return 0;
}

