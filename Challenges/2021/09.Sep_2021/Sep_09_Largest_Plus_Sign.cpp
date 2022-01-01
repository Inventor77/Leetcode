// ------------------------- O(N^3) BruteForce -------------------------------



// ---------------------------------------------------------------------------



// ------------------------------O(N^2) using DP------------------------------
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector < vector < int >> a(n, vector<int>(n, 1));
        for (auto& x : mines) a[x[0]][x[1]] = 0;
        vector<vector<int>> left = a, right = a, up = a, down = a;
        int m = n;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) left[i][j] = (left[i][j] == 1 ? left[i][j - 1] + 1 : 0);
        }

        for (int i = 0; i < n; i++) {
            for (int j = m - 2; j >= 0; j--) right[i][j] = (right[i][j] == 1 ? right[i][j + 1] + 1 : 0);
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) up[i][j] = (up[i][j] == 1 ? up[i - 1][j] + 1 : 0);
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < m; j++) down[i][j] = (down[i][j] == 1 ? down[i + 1][j] + 1 : 0);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans = max(ans, min({ left[i][j], right[i][j], down[i][j], up[i][j] }));
            }

        }
        return ans;

    }
};

// ---------------------------------------------------------------------------



// --------------------- 60 ms Submission ------------------------------------

// class Solution {
// public:
//     int orderOfLargestPlusSign(int n, vector<vector<int>>& mine) {
//         int dp[n + 2][n + 2][4];
//         memset(dp, 1, sizeof(dp));
//         for (int i = 1;i <= n;i++) {
//             for (int j = 1;j <= n;j++) {
//                 dp[i][j][0] = 1;dp[i][j][1] = 1;dp[i][j][2] = 1;dp[i][j][3] = 1;
//             }
//         }
        // for (int i = 0;i < mine.size();i++) {
        //     for (int j = 0;j < 4;j++)
        //         dp[mine[i][0] + 1][mine[i][1] + 1][j] = 0;
        // }

        // for (int i = 0;i <= n + 1;i++) {
        //     for (int j = 0;j < 4;j++) {
        //         dp[i][0][j] = 0;dp[i][n + 1][j] = 0;
        //         dp[0][i][j] = 0;dp[n + 1][i][j] = 0;
        //     }
        // }
        // for (int i = 1;i <= n;i++) {
        //     for (int j = 1;j <= n;j++) {
        //         //  cout<<dp[i][j][0]<<" ";
        //         if (dp[i][j][0] != 0)
        //             dp[i][j][0] += dp[i - 1][j][0];
        //         if (dp[i][j][1] != 0)
        //             dp[i][j][1] += dp[i][j - 1][1];
            }
            // cout<<"\n";
        // }
        // int ans = 0;
        // for (int i = n;i >= 1;i--) {
        //     for (int j = n;j >= 1;j--) {
        //         if (dp[i][j][2] != 0)
        //             dp[i][j][2] += dp[i + 1][j][2];
        //         if (dp[i][j][3] != 0)
        //             dp[i][j][3] += dp[i][j + 1][3];
        //         //cout<<dp[i][j][0]<<" ";
        //         int mi = INT_MAX;
        //         for (int k = 0;k < 4;k++) {
        //             mi = min(mi, dp[i][j][k]);
        //         }
        //         //cout<<mi<<" ";
        //         ans = max(ans, mi);
        //     }
            // cout<<"\n";
//         }
//         return ans;
//     }
// };

// ---------------------------------------------------------------------------


// ------------------- 17600KB Submission ------------------------------------

// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
// #pragma GCC optimize("unroll-loops")
// #define Fast ios_base::sync_with_stdio(0);cin.tie(0);

// #define grid matrix
// class Solution {
// public:
//     int N;
//     int dfs(int x, int y) {
        //         auto isValid = [&](int x,int y){
        //             if(x<0 ||  y<0 || x>=N || y>=N)return false;
        //             return true;
        //         };

    //     if (matrix[x][y] != 1)return 0;

    //     int mx = 1e9;

    //     int i = x, j = y;
    //     int  m = 1;

    //     while (x + m < N && y + m < N && x - m >= 0 && y - m >= 0 && grid[x + m][y] == 1 && grid[x][y + m] == 1 && grid[x - m][y] == 1 && grid[x][y - m] == 1)++m;
    //     return m;
    // }

    // bool matrix[501][501];

    // int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {

    //     memset(matrix, 1, sizeof matrix);
        // vector<vector<bool>>matrix(n, vector<int>(n, 1));
//         N = n;

//         for (auto& it : mines) {
//             matrix[it[0]][it[1]] = 0;
//         }

//         int sz = 0;

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 sz = max(dfs(i, j), sz);
//             }
//         }
//         return sz;

//     }
// };

// ---------------------------------------------------------------------------
