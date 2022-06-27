class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> v, u;
        for(int i = 0; i < arr.size(); i++) {
            v[arr[i]]++;
        }
         bool ans = true;
        for(auto it : v) {
            u[it.second]++;
        }
        for(auto itt : u) {
            if (itt.second > 1) ans = false;
        }
        return ans;
    }
};