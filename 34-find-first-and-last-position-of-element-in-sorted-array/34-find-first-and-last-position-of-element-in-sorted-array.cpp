class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
	int s = 0, e = nums.size()-1;
	vector<int> ans(2, -1);
        
    // for first occurrence
        while(s<=e){
           int mid= (s+e)/2;
            if(nums[mid]==target){
               ans[0]=mid;
               e=mid-1;
           } 
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        
        //for last occurrence
        s = 0, e = nums.size()-1;
         while(s<=e){
           int mid= (s+e)/2;
            if(nums[mid]==target){
               ans[1]=mid;
                s=mid+1;
           } 
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
return ans;
    }
};