class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for(int i=0;i<strs[0].size();++i){
            for(int j=1;j<strs.size();++j){
                if(strs[j][i]!=strs[0][i]) return prefix;
            }
              prefix+=strs[0][i];
        }
        return prefix;
    }
};