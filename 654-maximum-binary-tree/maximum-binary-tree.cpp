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
    unordered_map<int, int> mp;
    TreeNode* solve(vector<int>& nums, int start, int end){
        if(start>end) return nullptr;
        int maxNum=INT_MIN;
        for(int i=start;i<=end;i++) maxNum=max(maxNum, nums[i]);
        int i=mp[maxNum];
        TreeNode* root=new TreeNode(maxNum);
        root->left=solve(nums, start, i-1);
        root->right=solve(nums, i+1, end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        int start=0;
        int end=nums.size()-1;
        TreeNode* ans=solve(nums, start, end);
        return ans;
    }
};