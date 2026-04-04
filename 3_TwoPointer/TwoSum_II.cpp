#include<iostream>
#include<vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;

    while(left < right) { 
        if(numbers[left] + numbers[right] > target) right--;
        else if(numbers[left] + numbers[right] < target) left++;
        else return{left + 1, right + 1};
    }
    return{};
}

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(numbers, target);
    for(int i : result) {
        cout<< i << " ";
    }
    cout<<endl;
}
    
