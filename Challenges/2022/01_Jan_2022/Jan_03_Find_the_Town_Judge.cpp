class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inout(n + 1, 0);

        for (auto t : trust) {
            inout[t[0]]--; 
            inout[t[1]]++; 
        }
        for (int i = 1; i < n + 1; i++) {   
            if (inout[i] == n - 1) return i;
        }
        return -1;
    }
};
