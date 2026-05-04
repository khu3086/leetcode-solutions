class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1&&nums[0]==0) return true;
        int maxReach=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>maxReach) return false;
            maxReach=max(maxReach, nums[i]+i);
        }
        return maxReach;
    }
};