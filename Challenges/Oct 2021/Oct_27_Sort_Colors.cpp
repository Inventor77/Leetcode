class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = nums.size() - 1;
        while (one <= two) {

            if (nums[two] == 2) {
                two--;
            }
            else if (nums[two] == 1) {
                nums[two] = nums[one];
                nums[one] = 1;
                one++;
            }
            else {
                nums[two] = nums[zero];
                nums[zero] = 0;

                if (zero == one)
                    one++;
                zero++;
            }
        }
    }
};