// 188. Best Time to Buy and Sell Stock IV

// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete at most k transactions.

// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).



class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        return profit_util(2*k, prices, -1, 0); // one transaction means buy and sell
    }
    int profit_util(int k, vector<int>& prices, int flag, int index){
        if(k<=0 || index == prices.size()){
            return 0;
        }
        return max (profit_util(k-1, prices, flag*-1, index+1) + flag * prices[index],
            profit_util(k, prices, flag, index+1));
    }
};



class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        return profit_util2(2*k, prices, 0);
    }
    int profit_util2(int k, vector<int>& prices, int index){
        if(k<=0 || index == prices.size()){
            return 0;
        }
        int flag = k%2 == 0 ? -1 : 1;
        return max(profit_util2(k-1, prices, index+1) + flag * prices[index],
            profit_util2(k, prices, index+1));
    }
};

class Solution{ // 最后一个测试用例过不去，一亿次的交易，prices也非常长。out of memory,想办法缩小cache
public:
    int maxProfit(int k, vector<int>& prices){
        vector<vector<int> > cache(2*k+1, vector<int>(prices.size(), INT_MAX));
        return profit_util3(2*k, prices, 0, cache);
    }
    int profit_util3(int k, vector<int>& prices, int index, vector<vector<int> >& cache){
        if(k <= 0 || index == prices.size()){
            return 0;
        }
        if(cache[k][index] != INT_MAX){
            return cache[k][index];
        }
        int flag = k%2 == 0? -1 : 1;
        return cache[k][index] = max(profit_util3(k-1, prices, index+1, cache) + flag * prices[index],
            profit_util3(k, prices, index+1, cache));
    }
};

// class Solution{
// public:
//     int maxProfit(int k, vector<int>& prices){

//     }
//     int profit_util4(int k, vector<int>& prices, int index, vector<vector<int> >& cache){
//         if(k<=0 || index == prices.size()){
//             return 0;
//         }
//         if(cache[k][index%2] != INT_MAX){
//             return cache[k][index%2];
//         }
//         int flag = k%2 == 0 ? -1 : 1;
//         return cache[k][index%2] = max(profit_util4(k-1, prices, index+1, cache) + flag * prices[index],
//             profit_util4(k, prices, index+1, cache));
//     }
// };


class Solution{  // This is accepted
    int maxProfit(int k, vector<int>& prices){
        if(prices.size() == 0)
            return 0;
        if(k >= prices.size()){ // 如果交易次数大于天数，那么意味着可以无限次进行交易。
            return solve_max_profit_k_bigger(k, prices);
        }
        vector<vector<int> > cache(2*k+1, vector<int>(prices.size(), INT_MAX));
        return profit_util5(2*k, prices, 0, cache);
    }
    int profit_util5(int k, vector<int>& prices, int index, vector<vector<int> >& cache){
        if(k <= 0 || index == prices.size()){
            return 0;
        }
        if(cache[k][index] != INT_MAX){
            return cache[k][index];
        }
        int flag = k%2 == 0? -1 : 1;
        return cache[k][index] = max(profit_util5(k-1, prices, index+1, cache) + flag * prices[index],
            profit_util5(k, prices, index+1, cache));
    }
    int solve_max_profit_k_bigger(int k, vector<int>& prices){
        int res = 0;
        for(int i=0; i<prices.size()-1; i++){
            if(prices[i] < prices[i+1])
                res += prices[i+1] - prices[i];
        }
        return res;
    }
};