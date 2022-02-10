class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0, ans = 0;
        mp[sum] = 1;
        for (auto it : nums) {
            sum += it;
            int find = sum - k;
            if (mp.find(find) != mp.end()) {
                ans += mp[find];
            }
            mp[sum]++;
        }
        return ans;
    }
};