class BSTIterator {
public:

    TreeNode* inorder(TreeNode* cur, TreeNode* pre) {
        if (cur == nullptr) return pre;
        TreeNode* now = inorder(cur->left, pre);
        now->right = cur;
        now->left = nullptr;
        return inorder(cur->right, now->right);
    }

    BSTIterator(TreeNode* root) {
        inorder(root, node);
    }

    int next() {
        node = node->right;
        return node->val;
    }

    bool hasNext() {
        return node->right != nullptr;
    }
private:
    TreeNode* node = new TreeNode(0);
};