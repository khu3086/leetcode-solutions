class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=nums[0];
        int maxsum=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            curr=max(nums[i], nums[i]+curr);
            maxsum=max(maxsum, curr);
        }
        return maxsum;
    }
};