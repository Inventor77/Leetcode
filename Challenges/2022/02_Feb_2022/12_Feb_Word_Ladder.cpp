class Solution {
public:
    int ladder;

    int bfs(string& beginword, string& endword, unordered_set<string>& st)
    {
        queue<string> qq; 
        qq.push(beginword);
        while (!qq.empty())
        {
            int n = qq.size();
            ladder++;

            while (n--)
            {
                string cur = qq.front(); 
                qq.pop();
                for (int i = 0;i < cur.length();i++) 
                {
                    string temp = cur;
                    for (char ch = 'a';ch <= 'z';ch++)
                    {
                        temp[i] = ch; 
                        if (temp == cur) 
                            continue;
                        if (temp == endword) return ladder + 1; 
                        if (st.count(temp)) 
                        {
                            qq.push(temp); 
                            st.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        int ladder = 0;
        for (auto& it : wordList) st.insert(it);
        if (st.count(endWord) == 0) return ladder;
        return bfs(beginWord, endWord, st);
    }
};