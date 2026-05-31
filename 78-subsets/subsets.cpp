class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& nums, int idx, vector<int> curr){
        if(idx==nums.size()){
            ans.push_back(curr);
            return;
        }
        helper(ans, nums, idx+1, curr);
        curr.push_back(nums[idx]);
        helper(ans, nums, idx+1, curr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        int idx=0;
        helper(ans, nums, idx, curr);
        return ans;
    }
};