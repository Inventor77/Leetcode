class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int letter[26];
        for (int i = 0;i < s.size();i++) {
            letter[s[i] - 'a'] = i;
        }

        int i = 0;
        while (i < s.size()) {
            int end = letter[s[i] - 'a'];
            int j = i;
            while (j != end) {
                end = max(end, letter[s[j++] - 'a']);
            }

            ans.push_back(j - i + 1);
            i = j + 1;
        }

        return ans;
    }
};
