class Solution {
public:
    int rec(int i, vector<int> &dp) {
        if(i <= 1) return i;
        if(dp[i] != -1) return dp[i];
        return dp[i] = rec(i - 1, dp) + rec(i - 2, dp);
    }
    
    int fib(int n) {
        vector<int> v(n + 1, -1);
        return rec(n, v);
    }
};