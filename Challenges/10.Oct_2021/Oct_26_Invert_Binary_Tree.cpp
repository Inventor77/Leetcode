class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return root;
        else {
            invertTree(root->left);
            invertTree(root->right);
            swap(root->left, root->right);
            return root;
        }
    }
};
