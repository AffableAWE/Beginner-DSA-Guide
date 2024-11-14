#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;
 
bool isAnagram(string s, string t) {
    if(s.length() != t.length()) return false;

    unordered_map<char,int> char_count;

//     for(int i=0; i<s.length(); i++) {
//         char_count[s[i]]++;
//     }

    for(char c : s) {
        char_count[c]++;
    }

//     for(int i=0; i<t.length(); i++) {
//         char_count[t[i]]--;
//         if(char_count[t[i]] < 0) return false;
//     }

    for(char c : t) {
        char_count[c]--;
        if(char_count[c] < 0) return false;
    }

    for(auto it : char_count) {
        if (it.second != 0) {
                return false;
            }
        }

        return true;
}

int main() {
    string s = "anagram";
    string t = "nagaram";
    if(isAnagram(s,t)) {
        cout<< "Given strings are  anagram" << endl;
    }
    else {
        cout<<"Given strings aren't Anagram"<< endl; 
    }
    return 0;
}
