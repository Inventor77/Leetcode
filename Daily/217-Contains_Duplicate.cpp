class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> u;
        for (int i = 0; i < nums.size(); i++)
        {
            u[nums[i]]++;
        }

        for (auto it = u.begin();it != u.end(); it++)
        {
            if (it->second >= 2)
            {
                return true;
            }
        }
        return false;
    }
};