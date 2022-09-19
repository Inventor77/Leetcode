class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, vector<string>> fullPath;
        for(string s : paths)
        {
            int start = 0;
            int isDir = true;
            string dir = "";
            string file = "";
            for(int i = 0; i < s.size(); i++)
            {
                if(s[i] == ' ' && isDir)
                {
                    dir = s.substr(start, i-start);
                    start = i+1;
                    isDir = false;
                }
                else if(s[i] == '(')
                {
                    file = dir+'/'+s.substr(start, i-start);
                    start = i+1;
                }
                else if(s[i] == ')')
                {
                    string content = s.substr(start, i-start);
                    fullPath[content].push_back(file);
                    file = "";
                    start = i+2;
                }
            }
        }
        vector<vector<string>> out;
        for(map<string, vector<string>>::iterator it = fullPath.begin(); it != fullPath.end(); it++)
        {
            if(it->second.size() > 1) out.push_back(it->second);
        }
        return out;
        
    }
};