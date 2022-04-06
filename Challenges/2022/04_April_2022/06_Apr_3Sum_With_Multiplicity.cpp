class Solution {
public:

    int threeSumMulti(vector<int>& a, int t)
    {
        int n = a.size();
        unordered_map<int, long> mp;
        int i, j, m = 1e9 + 7;
        long c = 0;

        for (i = 0;i < n;i++)
        {
            c += mp[t - a[i]];

            for (j = 0;j < i;j++)
                mp[a[i] + a[j]]++;
        }

        return c % m;
    }
};