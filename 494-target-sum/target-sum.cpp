class Solution {
public:
    void helper(vector<int>& nums, int target, int idx, int currSum, int& count){
        if(idx==nums.size()){
            if(currSum==target) count++;
            return;
        }
        helper(nums, target, idx+1, currSum+nums[idx], count);
        helper(nums, target, idx+1, currSum-nums[idx], count);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int currsum=0;
        int count=0;
        int idx=0;
        helper(nums, target, idx, currsum, count);
        return count;
    }
};