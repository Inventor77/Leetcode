class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top = 0, down = n - 1, left = 0, right = n - 1;
        int value = 1;
        vector<vector<int>> ans(n, vector<int>(n));
        while (top <= down && left <= right) {
            for (int i = left;i <= right;i++) {
                ans[top][i] = value++;
            }
            top++;
            for (int i = top;i <= down;i++) {
                ans[i][right] = value++;
            }
            right--;
            for (int i = right;i >= left;i--) {
                ans[down][i] = value++;
            }
            down--;
            for (int i = down;i >= top;i--) {
                ans[i][left] = value++;
            }
            left++;
        }
        return ans;
    }
};