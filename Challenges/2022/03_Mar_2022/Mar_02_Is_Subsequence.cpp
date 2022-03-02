class Solution {
public:
    bool isSubsequence(string s, string t) {
        int count = 0;
        int i = 0, j = 0;


        while (j < t.length())
        {
            if (s[i] == t[j])
            {
                count++;
                i++;

            }
            j++;
        }

        return (count == s.length());
    }
};