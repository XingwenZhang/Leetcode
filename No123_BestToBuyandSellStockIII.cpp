// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete at most two transactions.


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()){
        	return 0;
        }
        vector<int> left_profit(prices.size(), 0);
        vector<int> right_profit(prices.size(), 0);

        int min_price = prices[0];
        for(int i=1; i<prices.size(); i++){
        	min_price = min(min_price, prices[i]);
        	left_profit[i] = max(left_profit[i-1], prices[i] - min_price);
        }

        int max_price = prices[prices.size()-1];
        for(int j=prices.size()-2; j>=0; j--){
        	max_price = max(max_price, prices[j]);
        	right_profit[j] = max(right_profit[j+1], max_price - prices[j]);
        }
        int res = 0;
        for(int k=0; k<prices.size(); k++){
        	res = max(res, left_profit[k]+right_profit[k]);
        }

        return res;
    }
};