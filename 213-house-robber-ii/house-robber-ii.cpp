class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int first=nums[0];
        int second=max(nums[0], nums[1]);
        int res=second;
        for(int i=2;i<n-1;i++){
            res=max(nums[i]+first, second);
            first=second;
            second=res;
        }

        first=nums[n-1];
        second=max(nums[n-1], nums[n-2]);
        int res2=second;
        for(int i=n-3;i>=1;i--){
            res2=max(nums[i]+first, second);
            first=second;
            second=res2;
        }
        return max(res, res2);
    }
};