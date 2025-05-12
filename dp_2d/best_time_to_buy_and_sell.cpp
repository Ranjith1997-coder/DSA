#include"../stdc++.h"

using namespace std;

int max_profit_util(vector<int> stock_prices, int index, int buy_sell, int profit) {
    if (index >= stock_prices.size()) {
        return profit;
    }

    if (buy_sell == -1) {
        return max(max_profit_util(stock_prices, index + 1, stock_prices[index], profit), 
                    max_profit_util(stock_prices, index + 1, buy_sell, profit));
    } else {
        return max(max_profit_util(stock_prices, index + 1, stock_prices[index], profit), 
                    max_profit_util(stock_prices, index + 2, -1 , profit + (stock_prices[index] - buy_sell)));
    }
}

int max_profit_function(vector<int> stock_prices) {

    return max_profit_util(stock_prices, 0, -1, 0);
}

int main(){

    vector<int> stock_prices = {1,3,4,0,4};

    int max_profit = max_profit_function(stock_prices);
}