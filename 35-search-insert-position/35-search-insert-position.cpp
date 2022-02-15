class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, mid = 0, right = nums.size() - 1;
        while (left < nums.size() && left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (target < nums[mid]) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};