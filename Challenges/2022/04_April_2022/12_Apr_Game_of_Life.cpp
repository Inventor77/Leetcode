class Solution {
public:
    int work(vector<vector<int>>& board, int r, int c) {
        int m = board.size(), n = board[0].size(), cnt = 0;
        for (int i = -1;i <= 1;i++)
            for (int j = -1;j <= 1;j++) {
                if (i == 0 and j == 0) continue;
                int newr = r + i, newc = c + j;
                if (newr < 0 or newr >= m or newc < 0 or newc >= n) continue;
                cnt += (board[newr][newc] % 2);
            }
        if (board[r][c] == 1) return cnt == 2 or cnt == 3;
        else return cnt == 3;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0;i < m;i++)
            for (int j = 0;j < n;j++) {
                int old = board[i][j];
                int newval = work(board, i, j);
                board[i][j] = old + 2 * newval;
            }
        for(auto &r:board)
            for(auto &ele:r) ele=ele/2;
    }
};