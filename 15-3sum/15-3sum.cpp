class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)(nums.size()) - 2; i++)
        {
            if (i == 0 || (i > 0 &&  nums[i] != nums[i - 1])) {
                int left = i + 1, right = (int)(nums.size()) - 1,sum = 0 - nums[i];
                while (left < right) {
                    if (nums[left] + nums[right] == sum) {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[left]);
                        temp.push_back(nums[right]);
                        ans.push_back(temp);
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[left] == nums[right - 1]) right--;
                        left++; right--;
                    }
                    else if (nums[left] + nums[right] < sum) left++;
                    else right--;
                }
            }
        }
        return ans;
    }
};