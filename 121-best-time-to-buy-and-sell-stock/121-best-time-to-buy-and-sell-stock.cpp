class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_elem = prices[0], ans =0;
        for(int i = 0; i < prices.size(); i++) {
            min_elem = min(min_elem, prices[i]);
            ans = max(ans, prices[i] - min_elem);
        }
        return ans;
    }
};