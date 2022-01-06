static constexpr int dest = 0;
static constexpr int from = 1;
static constexpr int to = 2;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        array<int, 1001> dp;
        memset(dp.data(), 0, dp.size() * sizeof(int));

        for (auto& trip : trips) {
            dp[trip[from]] += trip[dest];
            dp[trip[to]] += -trip[dest];
        }

        uint64_t totalSoFar = 0;

        for (auto& v : dp) {
            totalSoFar += v;
            if (totalSoFar > capacity) return false;
        }
        return true;
    }
};