\\ Iterative
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt = 0;
        int plots = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1) {
                    plots++;
                    if (j + 1 < m && grid[i][j + 1]) cnt++;
                    if (j - 1 >= 0 && grid[i][j - 1]) cnt++;
                    if (i + 1 < n && grid[i + 1][j]) cnt++;
                    if (i - 1 >= 0 && grid[i - 1][j]) cnt++;
                }
            }
        }
        int ans = 4 * plots - cnt;
        return ans;
    }
};

\\ DFS