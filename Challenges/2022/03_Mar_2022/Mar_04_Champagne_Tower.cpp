class Solution {
public:
    double dp[101][101];
    int p;
    double pourFunction(int i, int j)
    {
        if (i == 0 && j == 0)
        {
            return p;
        }
        if (i < 0 || j < 0 || j > i) return 0;
        if (dp[i][j] > -1) return dp[i][j];
        double l = pourFunction(i - 1, j - 1);
        double r = pourFunction(i - 1, j);
        double left = 0, right = 0;
        if (l > 1)
        {
            left = (l - 1) / 2;
        }
        if (r > 1)
        {
            right = (r - 1) / 2;
        }
        dp[i][j] = left + right;
        return left + right;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        p = poured;
        if (poured <= 0) return 0;
        memset(dp, -1, sizeof(dp));
        double ans = pourFunction(query_row, query_glass);
        return ans > 1 ? 1 : ans;
    }
};