class Solution {
public:
    int numSquares(int n) {

        static vector<int>cnt({ 0 });
        while (cnt.size() <= n) {
            int sqr = INT_MAX;
            int m = cnt.size();
            for (int i = 1;i * i <= m;i++) {
                sqr = min(sqr, cnt[m - i * i] + 1);
            }
            cnt.push_back(sqr);
        }

        return cnt[n];
    }
};