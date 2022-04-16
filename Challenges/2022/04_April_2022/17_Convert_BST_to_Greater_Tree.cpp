class Solution {
private:
    int helper(TreeNode* root, int parentNewVal) {
        if (!root) { return parentNewVal; }
        int rightSum = helper(root->right, parentNewVal);
        root->val += rightSum;
        int leftSum = helper(root->left, root->val);
        return leftSum;
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int answer = helper(root, 0);
        return root;
    }
};