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
    void count(TreeNode* root, int &ans, vector<int> &v ) {
        if(root == NULL) return;
        v[root->val]++;
        count(root->left, ans, v);
        count(root->right, ans, v);
        if(root->left == NULL && root->right == NULL) {
            int cnt = 0;
            for(int i = 0; i <=9; i++) {
                if(v[i] % 2 != 0) cnt++;
            }
            if(cnt <= 1) ans++;
        }
        v[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        vector<int> v(10, 0);
        count(root, ans, v);
        return ans;
    }
};