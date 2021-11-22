class Solution {
public:
    int getSufix(TreeNode* root) {
        while (root->left) root = root->left;
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        else if (root->val == key) {
            if (!root->left) return root->right;
            else if (!root->right) return root->left;
            else {
                root->val = getSufix(root->right);
                root->right = deleteNode(root->right, root->val);
            }
        }
        else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        else root->right = deleteNode(root->right, key);
        return root;
    }
};