class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n < 3) {
            return 0;
        }

        int res = 0;
        unordered_map<long long, int> dp[n];
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                // [note]: have to use long long here to avoid overflow
                long long diff = (long long)A[i] - (long long)A[j];
                if (dp[j].find(diff) != dp[j].end()) {
                    res += dp[j][diff];
                    dp[i][diff] += dp[j][diff];
                }
                // [note]: here is the length 2 seq, we cannot add it to final res but have to cache it for further use
                ++dp[i][diff];
            }
        }

        return res;
    }
};