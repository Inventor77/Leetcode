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
    
    TreeNode* preOrder(TreeNode* root, int val, int depth){
        if(root == NULL){
            return NULL;
        }
        if(depth == 2){
            TreeNode* leftNode = new TreeNode(val);
            TreeNode* rightNode = new TreeNode(val);
            
            leftNode->left = root->left;
            rightNode->right = root->right;
            root->left = leftNode;
            root->right = rightNode;
            
            return root;
        }
        
        root->left = preOrder(root->left, val, depth-1);
        root->right = preOrder(root->right, val, depth-1);
        
        return root;
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }   
        return preOrder(root, val, depth);
    }
};
