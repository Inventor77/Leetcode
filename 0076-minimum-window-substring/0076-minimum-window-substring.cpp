class Solution {
public:
    string minWindow(string s, string t) {
        
        int hashmap[256] = {0};
        int m = s.size(), n = t.size();
        
        for (int i = 0; i < n; ++ i) {
            hashmap[t[i]] ++;
        }
        
        int minLen = -1, len = 0, validLen = 0;
        int start = 0, min_start;

        for (int i = 0; i < m; ++ i) {
            
            if (hashmap[s[i]] > 0) validLen ++;
            hashmap[s[i]] --;
            len ++;

            while (hashmap[s[start]] < 0) {
                hashmap[s[start]] ++;
                start ++;
                len --;
            }
            
            if (validLen == n && (len < minLen || minLen == -1)) {
                minLen = len;
                min_start = start;
            }
        }
        
        if (validLen < n) return "";
        
        return s.substr(min_start, minLen);
    }
};