class Solution {
public:
    bool detectCapitalUse(string word)
    {
        int n = word.size();
        string s = word;

        transform(s.begin(), s.end(), s.begin(), ::toupper);
        if (s == word)
        {
            return true;
        }
        s = word;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        if (s == word)
        {
            return true;
        }
        s[0] = toupper(s[0]);
        if (s == word)
        {
            return true;
        }
        return false;
    }
};