class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int dp1=nums[0];
        int dp2=max(nums[0], nums[1]);
        int res=dp2;
        for(int i=2;i<n-1;i++){
            res=max(dp1+nums[i], dp2);
            dp1=dp2;
            dp2=res;
        }
        dp1=nums[n-1];
        dp2=max(nums[n-1], nums[n-2]);
        int res2=dp2;
        for(int i=n-3;i>0;i--){
            res2=max(dp1+nums[i], dp2);
            dp1=dp2;
            dp2=res2;
        }
        return max(res, res2);
    }
};