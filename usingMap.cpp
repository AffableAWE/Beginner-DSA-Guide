#include<iostream>
#include<unordered_map>
using namespace std;

/*
    Approach:
    The program reads a list of numbers and calculates the frequency of each number using an unordered map.
    Then, it processes multiple queries to return the frequency of specified numbers.
    This approach efficiently counts occurrences and allows for quick look-up of frequencies.
*/

int main() {
    int n;
    cin >> n;

    int arr[n];
    // Input elements into the array
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Store frequencies of elements in an unordered map
    unordered_map<int, int> mpp;
    for(int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    int q;
    cin >> q;
    // Process each query to output the frequency of the queried number
    while(q--) {
        int number;
        cin >> number;
        cout << mpp[number] << endl;
    }
}

