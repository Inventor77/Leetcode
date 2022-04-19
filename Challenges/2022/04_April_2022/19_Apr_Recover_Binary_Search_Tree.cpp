class Solution {
public:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* last;
    void inorder(TreeNode* root) {
        if (root == NULL) return;
        inorder(root->left);
        if (prev != NULL && (root->val < prev->val)) {
            if (first == NULL) {
                first = prev;
                last = root;
            }
            else
                last = root;
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = last = prev = NULL;
        inorder(root);
        if (first && last) swap(first->val, last->val);
    }
};