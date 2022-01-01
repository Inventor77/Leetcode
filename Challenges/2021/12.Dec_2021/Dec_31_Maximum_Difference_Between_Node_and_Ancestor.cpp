class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        return dfs(root, root->val, root->val);
    }

private:
    int dfs(TreeNode* root, int minV, int maxV) {
        if (!root) return 0;
        int curMaxV = max(abs(root->val - minV), abs(root->val - maxV));
        minV = min(minV, root->val);
        maxV = max(maxV, root->val);
        return max({ curMaxV, dfs(root->left, minV, maxV), dfs(root->right, minV, maxV) });
    }
};