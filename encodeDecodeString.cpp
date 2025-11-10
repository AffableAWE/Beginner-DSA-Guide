#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
using namespace std;

string encode(vector<string> &strs) {
    string encodedStr = "";
    for(const string &s : strs) {
        encodedStr += to_string(s.size()) + "#" + s;
    }
    return encodedStr;
}

vector<string> decode(string &str) {
    vector<string> decodedStrs; // This will store the final list of strings
    int i = 0;
    while (i < str.size()) {
        int delimiterPos = str.find('#', i); // Find the position of '#'
        int length = stoi(str.substr(i, delimiterPos - i)); // Extract the length
        i = delimiterPos + 1; // Move past '#'
        decodedStrs.push_back(str.substr(i, length)); // Extract the string and add to the result
        i += length; // Move the index past the current string
    }
    return decodedStrs;
}

int main() {
    vector<string> strs = {"They", "Not", "Like", "Us"};
    string encoded = encode(strs);
    cout << "Encoded: " << encoded << endl;
    vector<string> decoded = decode(encoded);
    cout << "Decoded: ";
    for (const string &s : decoded) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
