class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int fres = floor(n / 2);
        int ele = 0, count = 0, res = -1;;
        for (int i = 0;i < n;i++) {
            if (count == 0) {
                ele = nums[i];
            }
            if (nums[i] == ele) {
                count++;
            }
            else {
                count--;
            }
        }
        count = 0;
        for (int i = 0;i < n;i++) {
            if (nums[i] == ele) {
                count++;
            }
        }
        if (count > fres) {
            res = ele;
        }
        return res;
    }
};