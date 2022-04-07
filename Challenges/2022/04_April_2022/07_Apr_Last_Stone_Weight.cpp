class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        sort(s.begin(), s.end());
        while (s.size() > 1) {
            int i = s.size() - 1;
            int x = s[i], y = s[i - 1];
            s.pop_back();
            s.pop_back();
            if (x != y)s.push_back(x - y);
            sort(s.begin(), s.end());
        }
        if (s.size() == 0)return 0;
        return s[0];
    }
};