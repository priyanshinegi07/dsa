
//TC : O(n) SC : O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int price = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            if(price > prices[i]) {
                price = prices[i];
                continue;
            }
            profit = max(profit, prices[i] - price);

        }
        return profit;
    }
};