class Solution {
public:
    long long calculateSum(TreeNode* root){
        if(root == nullptr) return 0;
        return root->val + calculateSum(root->left) + calculateSum(root->right);
    }

    long long dfs(TreeNode* node, long long &maxVal, long long totsum){
        if(node == nullptr) return 0;

        long long left = dfs(node->left, maxVal, totsum);
        long long right = dfs(node->right, maxVal, totsum);

        long long currsum = node->val + left + right;
        long long leftsum = totsum - currsum;

        maxVal = max(maxVal, currsum * leftsum);

        return currsum;
    }

    int maxProduct(TreeNode* root) {
        long long totalsum = calculateSum(root);
        long long maxVal = 0;

        dfs(root, maxVal, totalsum);

        return maxVal % 1000000007;
    }
};
