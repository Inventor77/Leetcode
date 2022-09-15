class Solution {
public:
    vector<int> findOriginalArray(vector<int>& chng) {
        int n = chng.size();
        if(n&1)    return {};
        vector<int> ans;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)    mp[chng[i]]++;
        sort(chng.begin(),chng.end());
        for(int i=0;i<n;i++)
        {
            if(mp[chng[i]]==0)  continue;
            if(mp[chng[i]*2]==0)    return {};
            mp[chng[i]]--;
            mp[2*chng[i]]--;
            ans.push_back(chng[i]);                
        }
        return ans;
    }
};