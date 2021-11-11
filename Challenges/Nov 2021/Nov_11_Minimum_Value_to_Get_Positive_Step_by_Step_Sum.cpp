class Solution {
public:
    int minStartValue(vector<int>& nums)
    {
        int maxi = INT_MIN;
        int sum = 0;

        for (int i = 0;i < nums.size();i++)
        {
            sum += nums[i];
            maxi = max(0, max(maxi, -1 * sum));
        }
        return maxi + 1;
    }
};
