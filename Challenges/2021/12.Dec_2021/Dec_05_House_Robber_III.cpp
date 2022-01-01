class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> mem;
        return robRec(root, mem);
    }

private:
    int robRec(TreeNode* node, unordered_map<TreeNode*, int>& mem) {
        if (node == nullptr) {
            return 0;
        }

        if (mem.count(node) != 0) {
            return mem[node];
        }

        int maxWithNode = node->val;
        if (node->left != nullptr) {
            maxWithNode += robRec(node->left->left, mem) + robRec(node->left->right, mem);
        }
        if (node->right != nullptr) {
            maxWithNode += robRec(node->right->left, mem) + robRec(node->right->right, mem);
        }

        int maxWithoutNode = robRec(node->left, mem) + robRec(node->right, mem);

        return mem[node] = max(maxWithNode, maxWithoutNode);
    }
};