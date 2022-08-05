class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0], ans = 0; 
        for(int i = 0; i < prices.size(); i++) {
            min_price = min(min_price, prices[i]);
            ans = max(ans, prices[i] - min_price);
        }
        return ans;
    }
};