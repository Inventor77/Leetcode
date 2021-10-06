
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        vector<int> ans;
        auto it = map.begin();
        while (it != map.end()) {
            if (it->second == 2) {
                ans.push_back(it->first);
            }
            it++;
        }
        return ans;
    }
};

// 