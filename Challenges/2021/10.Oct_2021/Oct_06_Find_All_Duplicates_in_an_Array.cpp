
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

// Optimized Space Complexity Solution

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();

        for (int i = 0; i < n;i++) {
            int num = abs(nums[i]);
            // all numbers are positive, so we make the number negative to indicate that we saw it already.5
            if (nums[num - 1] < 0) res.push_back(num);
            else nums[num - 1] *= -1;
        }
        return res;
    }
};