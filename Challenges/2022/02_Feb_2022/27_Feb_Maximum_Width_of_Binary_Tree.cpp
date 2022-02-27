class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        int ans = 0;
        queue<pair<TreeNode*, int >>q;
        q.push({ root,0 });
        while (!q.empty()) {
            int size = q.size();
            int m_min = q.front().second;
            int first, last;
            for (int i = 0;i < size;i++) {
                int index = q.front().second - m_min;
                TreeNode* node = q.front().first;
                q.pop();
                if (i == 0) first = index;
                if (i == size - 1) last = index;

                if (node->left != NULL) {
                    q.push({ node->left, (long)index * 2 + 1 });
                }
                if (node->right != NULL) {
                    q.push({ node->right, (long)index * 2 + 2 });
                }
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};
