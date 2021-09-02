//  -------------------------------  Bruteforce O(N^2) ---------------------------------------

// class Solution {
// public:
//     int arrayNesting(vector<int>& nums) {
//         int ans = 0;
//         n = nums.size();
//         for (int i = 0; i < n; i++) {
//             unordered_set<int> u;
//             while (!u.count(nums[i]))
//             {
//                 u.insert(nums[i]);
//                 nums[i] = nums[nums[i]];
//             }
//             int s = u.size();
//             ans = max(ans, s);
//         }
//         return ans;
//     }
// };

//  ------------------------------------------------------------------------------------


//     -----------  O(N) ----------------

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), ans;
        unordered_set<int> s;

        for (int i = 0; i < n; i++) {
            int cnt = 0;

            while (!s.count(nums[i]))
            {
                s.insert(nums[i]);
                cnt++;
                nums[i] = nums[nums[i]];
            }
            ans = max(ans, cnt);
        }

        return ans;
    }
};

//  ----------------------------------------


// -------------------------------  4ms submission  ---------------------------------------

// class Solution {
// public:
//     int n;
//     vector<int> visit;
//     int arrayNesting(vector<int>& nums) {
//         int ans = 0;
//         n = nums.size();
//         visit = vector<int>(n, 0);
//         for (int i = 0; i < n; ++i) {
//             if (visit[i] == 0) {
//                 ans = max(ans, helper(nums, i));
//             }
//         }
//         return ans;
//     }
//     int helper(vector<int>& nums, int i) {
//         if (visit[i] == 1) return 0;
//         visit[i] = 1;
//         return 1 + helper(nums, nums[i]);
//     }
// };

// ---------------------------------------------------------------------------------------------