class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        for (int i = 0;i < n;i++)
        {
            ans += 'a';
        }
        k = k - n;
        int j = n - 1;
        while (k != 0 && j >= 0)
        {
            k = k + 1;
            int m = k % 26;
            int p = k / 26;
            if (p >= 1)
            {
                ans[j] = 'z';
                k = k - 26;
            }
            else {
                cout << m << " ";
                ans[j] = char(m + 97 - 1);
                k = k - m;
            }
            j--;
        }

        return ans;
    }
};