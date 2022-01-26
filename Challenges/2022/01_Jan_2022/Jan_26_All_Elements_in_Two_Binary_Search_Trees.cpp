class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& sorted) {
        if (root == NULL) return;
        inOrder(root->left, sorted);
        sorted.push_back(root->val);
        inOrder(root->right, sorted);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> sorted1;
        vector<int> sorted2;
        inOrder(root1, sorted1);
        inOrder(root2, sorted2);
        vector<int> ans(sorted1.size() + sorted2.size());
        merge(sorted1.begin(), sorted1.end(),
            sorted2.begin(), sorted2.end(), ans.begin());
        return ans;
    }
};