class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> map;
        for(int i = 0; i < n; i++) {
            if(map.find(target - nums[i]) != map.end()) {
                ans.push_back(map[target - nums[i]]);
                ans.push_back(i);
                break;
            }
            map[nums[i]] = i;
        }
        return ans;
    }
};