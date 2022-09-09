class Solution {
public:
    static bool sortcol(vector<int>& v1, vector<int>& v2) {
        if(v1[0]!=v2[0])
            return v1[0]>v2[0];
        return v1[1]<v2[1];
    }
 
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        int ans = 0, mx = INT_MIN;
        sort(properties.begin(), properties.end(), sortcol);
        mx = properties[0][1];      
        for(auto p:properties){
            if(mx>p[1]) ans++;
            else mx=p[1];
        }
        return ans;
    }
};