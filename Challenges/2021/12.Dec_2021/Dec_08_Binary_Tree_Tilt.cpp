class Solution {

public:

    int findTilt(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }

private:

    int solve(TreeNode* root, int& ans)
    {
        if (!root) return 0;

        int left = solve(root->left, ans);
        int right = solve(root->right, ans);

        ans += abs(left - right);

        return (root->val + left + right);
    }
};