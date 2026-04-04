#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> dailyTempreatures(vector<int>& tempreatures) {
    int n = tempreatures.size();
    vector<int> result(n,0);
    stack<int> indices;

    for(int i = 0; i<n; i++) {
        while(!indices.empty() && tempreatures[i] > tempreatures[indices.top()]) {
            int idx = indices.top();
            indices.pop();
            result[idx] = i - idx;
        }
        indices.push(i);
    }
    return result;
}

int main() {
    vector<int> tempreatures = {30, 38, 30, 36, 35, 40, 28};
    vector<int> result = dailyTempreatures(tempreatures);

    for(int days : result) {
        cout<< days << " ";
    }
    cout<<endl;
}


