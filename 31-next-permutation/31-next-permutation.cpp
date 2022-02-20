class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int n = nums.size();
        int r=n-2;
        while(r>=0 && nums[r]>= nums[r+1]){
            r--;
        }
        int l=r+1;
        if(r>=0){
             while(l<n && nums[r] < nums[l]){
                l++;
            }
            l--;
            swap(nums[l], nums[r]);
        }
       
        sort(nums.begin()+r+1, nums.end());
              
    }
};