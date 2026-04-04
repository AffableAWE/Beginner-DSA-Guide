#include<iostream>
#include<stack>
#include<vector>

using namespace std;

long long toh(int n, int from, int to, int aux) {
    if(n == 0) return 0;
    if(n == 1) return 1;

    int count = 0;

    count = toh(n - 1, from , to, aux);
    
    count += 1;

    count += toh(n - 1, aux, to, from);

    return count;
}

int main() {
    int n = 2;
    int from = 1, to = 3, aux = 2;

    long long result = toh(n, from, to, aux);

    cout<< "Total counts : " << result << endl;
}




