class Solution {
public:
    int res = 0;
    void fun(TreeNode* root, int low, int high) {
        if (root == NULL) {
            return;
        }
        if (root->val < low) {
            fun(root->right, low, high);
        }
        if (root->val >= low && root->val <= high) {
            res += root->val;
            fun(root->left, low, high);
            fun(root->right, low, high);
        }
        if (root->val > high) {
            fun(root->left, low, high);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        fun(root, low, high);
        return res;
    }
};