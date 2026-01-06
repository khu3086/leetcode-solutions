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
    int maxLevelSum(TreeNode* root) {
        //using bfs
        int currlvl=1;
        int maxlvl=0;
        int maxsum=INT_MIN;
        queue<TreeNode*> q;
        if(!root) return maxlvl;
        q.push(root);
        while(q.size()!=0){
            int sum=0;
            int n=q.size();
            while(n){
                n--;
                TreeNode* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                sum+=node->val;
            }
            if(sum>maxsum){
                maxlvl=currlvl;
                maxsum=sum;
            }
            currlvl++;
        }
        return maxlvl;
    }
};