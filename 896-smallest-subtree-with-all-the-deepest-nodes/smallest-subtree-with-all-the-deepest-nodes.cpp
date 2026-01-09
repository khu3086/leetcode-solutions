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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<TreeNode*, TreeNode*> hash;
        vector<TreeNode*> lastLevel;
        //node->parent
        queue<TreeNode*> q;
        if(!root) return root;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            lastLevel.clear();
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                lastLevel.push_back(curr);
                if(curr->left){
                    hash[curr->left]=curr;
                    q.push(curr->left);
                }
                if(curr->right){
                    hash[curr->right]=curr;
                    q.push(curr->right);
                }
            }
            
        }
        unordered_set<TreeNode*> uset(lastLevel.begin(), lastLevel.end());
        while(uset.size()>1){
            unordered_set<TreeNode*> usetnext;
            for(auto x: uset) usetnext.insert(hash[x]);
            uset=usetnext;
        }
        return *uset.begin();
    }
};