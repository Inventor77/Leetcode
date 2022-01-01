/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
    vector<TreeNode*>  helper(int s, int e) {
        vector<TreeNode*>  v;
        if (s > e) {
            v.push_back(NULL);
            return v;
        }
        else if (s == e) {
            v.push_back(new TreeNode(s));
            return v;
        }
        for (int i = s; i <= e; i++)
        {
            auto left = helper(s, i - 1);
            auto right = helper(i + 1, e);
            for (auto& l : left)
            {
                for (auto& r : right)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    v.push_back(root);
                }
            }
        }
        return v;
    }
};


// ------------------ 0ms Submission -------------------

// class Solution {
// public:
//     vector<TreeNode*> dp[10][10];
//     vector<TreeNode*> generateTrees(int n) {
//         return Fun(1, n);
//     }

//     vector<TreeNode*> Fun(int start, int end) {
//         vector<TreeNode*> res;
//         if (start > end) {
//             res.push_back(NULL);
//             return res;
//         }
//         if (dp[start][end].size() != 0)
//             return dp[start][end];
//         for (int i = start; i <= end; i++) {
//             vector<TreeNode*> tempLeft = Fun(start, i - 1);
//             vector<TreeNode*> tempRight = Fun(i + 1, end);

//             for (int j = 0; j < tempLeft.size(); j++) {
//                 for (int k = 0; k < tempRight.size(); k++) {
//                     TreeNode* node = new TreeNode(i);
//                     node->left = tempLeft[j];
//                     node->right = tempRight[k];
//                     res.push_back(node);
//                 }
//             }
//         }
//         dp[start][end] = res;
//         return dp[start][end];
//     }
// };

// -----------------------------------------------------


// ---------------- 11500KB ----------------------------

// class Solution {
// public:
//     vector<TreeNode*> generateTrees(int n) {
//         vector<vector<vector<TreeNode*>>> dp(n + 2, vector<vector<TreeNode*>>(n + 1, { nullptr }));
//         for (int len = 1; len <= n; ++len) {
//             for (int i = 1; i + len - 1 <= n; ++i) {
//                 int j = i + len - 1;
//                 dp[i][j].clear();
//                 for (int k = i; k <= j; ++k) {
//                     for (auto* lhs : dp[i][k - 1]) {
//                         for (auto* rhs : dp[k + 1][j]) {
//                             TreeNode* node = new TreeNode(k);
//                             node->left = lhs;
//                             node->right = rhs;
//                             dp[i][j].push_back(node);
//                         }
//                     }
//                 }
//             }
//         }
//         return dp[1][n];
//     }
// };

// -----------------------------------------------------