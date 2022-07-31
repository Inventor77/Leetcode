/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root,vector<int> &temp, vector<string> &v) {
        if (root == NULL ) return;
        if(root->left == NULL && root->right == NULL) {
            string s = "";
            for(int i = 0; i < temp.size(); i++) s.append(to_string(temp[i]) + "->");
            s.append(to_string(root->val));
            v.push_back(s);
            return;
        }
        temp.push_back(root->val);
        dfs(root->left,temp, v);
        dfs(root->right, temp, v);
        temp.pop_back();
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        vector<int> temp;
        dfs(root,temp, v);
        return v;
    }
};