class Solution {
public:
    vector<int> productExceptSelf(vector<int>& n) {
        int i, l = 1, r = 1;
        vector<int> res(n.size());
        for (i = 0;i < n.size();i++)
        {
            res[i] = l;
            l *= n[i];
        }
        for (i = n.size() - 1;i >= 0;i--)
        {
            res[i] *= r;
            r *= n[i];
        }
        return res;
    }
};