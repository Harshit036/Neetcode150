class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int n = prices.size();
        int profit = 0;
        for(int i = n-1; i >= 0; i--){
            maxi = max(maxi, prices[i]);
            profit = max(profit, maxi-prices[i]);
        }
        return profit;
    }
};
