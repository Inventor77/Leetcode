// ---------------- Bruteforce O(2^n) (Recursion Method) ----------------------
// class Solution {
// public:
//     long ans = 0;
//     void helper(int idx, vector<long>& path, vector<int>& nums) {
//         if (idx >= nums.size()) {
//             if (path.size() >= 3) 
//             {
//                 long diff = path[1] - path[0];
//                 bool ok = 1;
//                 for (int i = 2; i < path.size(); i++)
//                 {
//                     if (path[i] - path[i - 1] ==  diff)
//                     {
//                         ok = 0;
//                         break;
//                     }
//                 }
//                 if (ok) ans++;
//             }
//             return;
//         }
//         path.push_back(nums[idx]);
//         helper(idx + 1, path, nums);
//         path.pop_back();
//         helper(idx + 1, path, nums);
//     }
//     int numberOfArithmeticSlices(vector<int>& nums) { 
//         int n = nums.size();
//         vector<long> path;
//         helper(0, path, nums);
//         return ans;
//     }
// };

// ----------------------------------------------------------------


// ----------------------- DP O(n^2) ------------------------------

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        long ans = 0;
        vector<unordered_map<long, long>> dp(n);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                long diff = (long)nums[i] - (long)nums[j];
                long sum = 0;
                if (dp[j].count(diff))
                {
                    sum = dp[j][diff];
                }
                dp[i][diff] += 1 + sum;
                ans += sum;
            }
        }
        return ans;
    }
};

// ----------------------------------------------------------------




// ------------------- 64ms Submission --------------------------------

// class Solution {
// public:
//     int numberOfArithmeticSlices(vector<int>& nums) {
//         int res = 0;
//         int n = nums.size();
//         unordered_map<int, vector<int>> idx_map;
//         for (int i = 0; i < n; ++i) {
//             idx_map[nums[i]].push_back(i);
//         }
//         vector<vector<int>> dp(n, vector<int>(n));
//         for (int i = 1; i < n; ++i) {
//             for (int j = 0; j < i; ++j) {
//                 long m = 2L * nums[j] - nums[i];
//                 if (m > INT_MAX || m < INT_MIN) continue;
//                 if (idx_map.count(m)) {
//                     for (const auto& k : idx_map[m]) {
//                         if (k < j) {
//                             dp[j][i] += dp[k][j] + 1;
//                         }
//                     }
//                 }
//                 res += dp[j][i];
//             }
//         }
//         return res;
//     }
// };

// ----------------------------------------------------------------



// ------------------- 11300KB Submission --------------------------------

// class Solution {
// public:
//     using ll = long long;
//     int numberOfArithmeticSlices(vector<int>& A) {
//         if (A.size() < 3) return 0;
//         int ret = 0, n = A.size();
//         unordered_map<ll, set<int>> ums;
//         unordered_set<int> equals;
//         for (int i = 0; i < n; i++) ums[A[i]].insert(i);
//         for (int i = 0; i < n - 2; i++) {
//             for (int j = i + 1; j < n - 1; j++) {
//                 ll d = (ll)A[j] - A[i];
//                 if (d == 0 && equals.count(A[i]) > 0) continue;
//                 if (d == 0) {
//                     equals.insert(A[i]);
//                     calc(0, ums[A[i]].size(), ret);
//                     continue;
//                 }
//                 dfs(ums, j, A[j], d, 2, ret);
//             }
//         }
//         return ret;
//     }

//     void dfs(unordered_map<ll, set<int>>& ums, int idx, int prev, ll d, int n, int& ret) {
//         ll next = prev + d;
//         auto it = ums.find(next);
//         if (it == ums.end()) { calc(d, n, ret); return; }
//         auto iter = it->second.upper_bound(idx);
//         if (iter == it->second.end()) { calc(d, n, ret); return; }
//         for (int i = 0; iter != it->second.end(); i++, iter++)
//             dfs(ums, *iter, next, d, i == 0 ? n + 1 : 3, ret);
//     }
//     void calc(ll d, int n, int& ret) {
//         if (n < 3) return;
//         if (d != 0) ret += n - 2;
//         else ret += pow(2, n) - 1 - n - n * (n - 1) / 2; // C(n,0)+C(n,1)+...C(n,n) = 2^n
//     }
// };

// ----------------------------------------------------------------
