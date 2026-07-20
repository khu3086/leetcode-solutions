class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int minsum=nums[0];
        int maxsum=nums[0];
        int currmin=nums[0];
        int currmax=nums[0];
        int total=nums[0];
        for(int i=1;i<nums.size();i++){
            currmin=min(nums[i], currmin+nums[i]);
            currmax=max(nums[i], currmax+nums[i]);
            maxsum=max(maxsum, currmax);
            minsum=min(minsum, currmin);
            total+=nums[i];
        }
        if(maxsum<0) return maxsum;
        return max(maxsum, total-minsum);
    }
};