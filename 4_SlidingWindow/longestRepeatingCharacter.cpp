#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;

int characterReplacement(string s, int k) {
    int left = 0;
    int right = 0;
    int maxCount = 0;
    int max_freq = 0;
    unordered_map<char, int> freqMap;

    while(right < s.size()) {
        // Expand the window by including the character at 'right'
        freqMap[s[right]]++;
        max_freq = max(max_freq, freqMap[s[right]]); // Track the most frequent character

        // If the window size minus the frequency of the most frequent character is greater than k
        // It meeans we need more replacements than allowed, so shrink the window

        if((right - left + 1) - max_freq > k) {
            freqMap[s[left]]--; // Remove the leftmost character from the window
            left++; // shrink the window by moving the left pointer
        }

        // Update the max Length of the valid window
        maxCount = max(maxCount, right - left + 1);
        right++; // Expand the Window 
    }
    return maxCount++;
}

int main() {
    string s = "AABABBA";
    int k = 1;
    int result = characterReplacement(s, k);
    cout<< "Longest Substring Length after Replacement: " <<result << endl;
    return 0;
}


