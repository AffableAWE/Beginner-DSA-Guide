#include<iostream>
#include<climits>
#include<unordered_map>
#include<string>

using namespace std;

string minWindow(string s, string t) {
    if(t.empty() || s.empty()) return "";

    // Frequency Map for t
    unordered_map<char, int> freqMap;

    for(char c : t) {
        freqMap[c]++;
    }

    // Variables to track the window
    int left = 0, right = 0;
    int minLeft = 0, minLen= INT_MAX;
    int count = 0; // Numbers of characters Matched
    
    // Sliding Window
    for(right = 0; right < s.length(); right++) {
        char currentChar = s[right];

        // if the current character is in t, decrement its count in freqMap
        if(freqMap.find(currentChar) != freqMap.end()) {
            freqMap[currentChar]--;
            if(freqMap[currentChar] >= 0) {
                count++;
            }
        }

        // When all characters are matched, try to shrink the window
        while(count == t.length()) {
            // Update the minimum Window
            if(right - left + 1 < minLen) {
            minLen = right - left + 1;
            minLeft = left;
        }

        // Try to remove the leftmost element to shrink the window
        char leftChar = s[left];
        if(freqMap.find(leftChar) != freqMap.end()) {
            freqMap[leftChar]++;
            if(freqMap[leftChar] > 0) {
                count --;
            }
        }
        left ++;
        }
    }

    // if minLen isn't updated, it means no valid window is found
    return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
}


int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    string result = minWindow(s, t);
    cout << "Minimum window substring: " << result << endl;
}
