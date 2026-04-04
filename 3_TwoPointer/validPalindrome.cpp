#include<iostream>
#include<algorithm>

using namespace std;

bool isPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;

    while(left < right) {

        // Skipping the Alphanumeric Chars
        while(left < right && !isalnum(s[left])) left++;
        while(left < right && !isalnum(s[right])) right--;

        if(tolower(s[left]) != tolower(s[right])) return false;
        left ++;
        right --;
    }
    return true;
}

int main() {
    string s = "A man, a plan, a canal: Panama";
    bool result;
    result = isPalindrome(s);
    cout<< result << endl;
}

