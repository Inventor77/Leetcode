class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> answer;
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++)
        {
            if (map.count(target - nums[i]))
            {
                answer.push_back(nums[i]);
                answer.push_back(target - nums[i]);
                break;
            }
            map[nums[i]]++;
        }
        bool flag1 = true, flag2 = true;
        int prev = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            if ((nums[i] == answer[0]) && flag1 && i != prev)
            {
                flag1 = false;
                answer[0] = i;
                prev = i;
            }
            if ((nums[i] == answer[1]) && flag2 && i != prev)
            {
                flag2 = false;
                answer[1] = i;
                prev = i;
            }
        }
        return answer;
    }
};