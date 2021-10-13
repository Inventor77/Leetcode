class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder, int max_val = INT_MAX) {
        if (i == preorder.size() || preorder[i] > max_val) return NULL;

        TreeNode* root = new TreeNode(preorder[i++]);

        root->left = bstFromPreorder(preorder, root->val);
        root->right = bstFromPreorder(preorder, max_val);

        return root;
    }

private:
    int i = 0;
};  