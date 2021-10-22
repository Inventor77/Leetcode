class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (auto a : s) freq[a]++;
        vector<vector<char>> buckets(s.size() + 1);
        for (auto [a, frq] : freq) buckets[frq].push_back(a);
        string res;
        for (int i = s.size(); i > 0; i--) {
            for (auto ch : buckets[i]) {
                res += string(i, ch);
            }
        }
        return res;
    }
};
