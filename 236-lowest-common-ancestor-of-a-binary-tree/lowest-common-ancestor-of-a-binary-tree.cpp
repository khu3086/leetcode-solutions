/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root||root==p||root==q) return root;
        TreeNode* leftn=lowestCommonAncestor(root->left, p, q);
        TreeNode* rightn=lowestCommonAncestor(root->right, p, q);
        if(leftn==nullptr) return rightn;
        else if(rightn==nullptr) return leftn;
        else return root;
    }
};