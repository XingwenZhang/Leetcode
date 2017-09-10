// 309. Best Time to Buy and Sell Stock with Cooldown


// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
// After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
// Example:

// prices = [1, 2, 3, 0, 2]
// maxProfit = 3
// transactions = [buy, sell, cooldown, buy, sell]


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int> > cache(2, vector<int>(prices.size(), INT_MAX));
        return profit_util(-1, 0, prices, cache);
    }
    int profit_util(int flag, int index, vector<int>& prices, vector<vector<int> >& cache){
        if(index >= prices.size()){
            return 0;
        }

        
        if(flag == -1){
            if(cache[0][index] != INT_MAX)
                return cache[0][index];
            return cache[0][index] = max(profit_util(flag, index+1, prices, cache), profit_util(flag*-1, index+1, prices, cache) - prices[index]);
        }
        else{
            if(cache[flag][index] != INT_MAX)
                return cache[flag][index];
            return cache[flag][index] = max(profit_util(flag, index+1, prices, cache), profit_util(flag*-1, index+2, prices, cache) + prices[index]);
    
        }

    }    
};