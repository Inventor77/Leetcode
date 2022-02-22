class Solution {
public:
    int titleToNumber(string s) {
        int n = s.length(); 
        if (n == 1) 
        {
            return (s[0] - 'A') + 1; 
        }
        int increase = 0; 
        int ans = 0; 
        for (int i = n - 1; i >= 0; i--) 
        {
            int pos = (s[i] - 'A') + 1; 
            ans = ans + (pos * pow(26, increase)); 
            increase++; 
        }
        return ans; 
    }
};