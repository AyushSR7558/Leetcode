class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() - 1;
        int maxi = prices[ n];
        int profit = 0;

        while(n >= 0) {
            profit = max(profit, maxi - prices[n]);        
            maxi = max(prices[n], maxi);
            n--;
        }

        return profit;
    }
};