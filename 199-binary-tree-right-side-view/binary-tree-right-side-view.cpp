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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        if(!root) return ans;
        //ans.push_back(root->val);
        while(!q.empty()){
            int sz=q.size();
            int curr=sz;
            while(sz){
                TreeNode* top=q.front();
                q.pop();
                if(top->right) q.push(top->right);
                if(top->left) q.push(top->left);
                if(curr==sz) ans.push_back(top->val);
                sz--;
            }
        }
        return ans;
    }
};