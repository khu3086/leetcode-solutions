class Solution {
public:
    int rob(vector<int>& nums) {
        int dp1=nums[0];
        int dp2=max(nums[0], nums[1]);
        int n=nums.size();
        if(n<=1) return nums[0];
        for(int i=2;i<n-1;i++){
            int tmp=dp2;
            dp2=max(dp2, dp1+nums[i]);
            dp1=tmp;
        }

        int dp3=nums[n-1];
        int dp4=max(nums[n-1], nums[n-2]);
        for(int i = n-3; i > 0; i--){
            int tmp = dp4;
            dp4 = max(dp4, dp3 + nums[i]);   // change here
            dp3 = tmp;
        }

        return max(dp4, dp2);
    }
};