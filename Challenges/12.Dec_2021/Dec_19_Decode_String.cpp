

class Solution {
public:
    string helper(string& s, int& i) {
        string res = "";
        int n = 0;
        while (i < s.size() && isdigit(s[i])) {
            n = n * 10 + (s[i] - '0');
            i++;
        }
        i++;
        while (i < s.size() && s[i] != ']') {
            if (isalpha(s[i])) res += s[i];
            if (isdigit(s[i])) res += helper(s, i);
            i++;
        }
        if (n != 0) {
            string r = "";
            for (int j = 0;j < n;j++) r += res;
            return r;
        }
        return res;
    }
    string decodeString(string s) {
        int i = 0;
        string res = "";
        while (i < s.size()) {
            if (isalpha(s[i])) res += s[i];
            else if (isdigit(s[i])) res += helper(s, i);
            i++;
        }
        return res;
    }
};
