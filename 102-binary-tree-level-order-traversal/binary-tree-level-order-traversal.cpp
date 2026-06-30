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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        if(root==nullptr) return {};
        while(q.size()){
            //this is curr lvl;
            int sz=q.size();
            vector<int> temp;
            while(sz){
                temp.push_back(q.front()->val);
                if(q.front()->left!=nullptr) q.push(q.front()->left);
                if(q.front()->right!=nullptr) q.push(q.front()->right);
                q.pop();
                sz--;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};