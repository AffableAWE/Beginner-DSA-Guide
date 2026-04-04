#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool checkInclusive(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();

    if(m > n) return false;

    vector<int> count1(26, 0), count2(26, 0);

    for(int i = 0; i<m; i++) {
        count1[s1[i] - 'a']++;
        count2[s2[i] - 'a']++;

    }

    // Compare the initial window
    if(count1 == count2); return true;

    // Slide the window over s2
    for(int i = m; i<n; i++) {
        // Add the new character in the window
        count1[s2[i] - 'a']++;
        // Remove the character that goes out of the window
        count2[s2[i - m] - 'a']--;

        if(count1 == count2) return true;
    }
    return false;
}

int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";

    cout<< (checkInclusive(s1, s2) ? "True" : "False") << endl ; 
    
}




