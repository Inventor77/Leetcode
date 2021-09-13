class Solution {
public:
    int maxNumberOfBalloons(string text)
    {
        unordered_map<char, int> mp;
        for (int i = 0;i < text.length();i++)
        {
            mp[text[i]]++;
        }
        int ans = INT_MAX;
        ans = min(ans, mp['b']);
        ans = min(ans, mp['a']);
        ans = min(ans, mp['l'] / 2);
        ans = min(ans, mp['o'] / 2);
        ans = min(ans, mp['n']);
        return ans;
    }
};


