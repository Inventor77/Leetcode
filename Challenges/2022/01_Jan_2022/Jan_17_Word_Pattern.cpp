class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int c = count(s.begin(), s.end(), ' ');

        if (c != pattern.size() - 1) {
            return false;
        }
        istringstream ss(s);
        unordered_map<string, char>W2C;
        unordered_map<char, string>C2W;
        for (int i = 0;i < pattern.size();i++) {
            ss >> s;
            if (W2C.count(s) == 0) {
                if (C2W.count(pattern[i]) == 0) {
                    W2C[s] = pattern[i];
                    C2W[pattern[i]] = s;
                }
                else {
                    return false;
                }
            }
            else {
                if (C2W.count(pattern[i]) == 0 || W2C[s] != pattern[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
