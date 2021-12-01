class Solution {
public:
    string reverseWords(string s) {
        string w = "";
        s += " ";
        vector<string> pre_ans;
        for (int i = 0; i < s.size(); i++)
        {
            if (isspace(s[i]) && w != "")
            {
                pre_ans.push_back(w);
                w = "";
            }
            if (!isspace(s[i]))
            {
                w += s[i];
            }
        }
        string ans = "";
        for (auto it = --pre_ans.end(); it != --pre_ans.begin(); it--)
        {
            ans += *it;
            if (it != pre_ans.begin()) {
                ans += " ";
            }
        }
        // ans.erase(--ans.end());
        return ans;
    }
};