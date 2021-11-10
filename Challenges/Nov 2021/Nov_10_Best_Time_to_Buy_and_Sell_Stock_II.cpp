class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int p = 0, c;
        for (int i = 1;i < prices.size();i++) {
            c = prices[i] - prices[i - 1];
            if (c > 0) {
                p += c;
            }
        }
        return p;

    }
};