#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& prices) {

    if(prices.size() < 2) return 0;

    int min_price = prices[0];
    int max_profit = 0;

    for(int i = 1; i<prices.size(); i++) {
        if(prices[i] < min_price) {
            min_price = prices[i];
        }

        int profit = prices[i] - min_price;

        if(profit > max_profit) {
            max_profit = profit;
        }
    }
    return max_profit;
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};

    int result = maxProfit(prices);

    cout<< result << endl;
}

