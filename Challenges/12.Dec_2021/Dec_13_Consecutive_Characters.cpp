class Solution {
public:
    int maxPower(string str) {
        int i = 0, j = 1;
        int n = str.length();
        int ans = 1;

        while (j < n)
        {
            if (str[j] != str[i])
            {
                ans = max(ans, j - i);
                i = j;
            }
            j++;
        }
        return max(j - i, ans);
    }
};