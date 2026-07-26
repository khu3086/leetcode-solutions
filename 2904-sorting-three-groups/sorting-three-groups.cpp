class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int dp1=0;
        int dp2=0;
        int dp3=0;
        for(auto num: nums){
            if(num==1){
                dp2++;
                dp2=min(dp2, dp1);
                dp3++;
                dp3=min(dp3, dp2);
            }
            if(num==2){
                dp1++;
                dp2=min(dp1, dp2);
                dp3++;
                dp3=min(dp3, dp2);
            }
            if(num==3){
                dp1++;
                dp2++;
                dp2=min(dp1, dp2);
                dp3=min(dp2, dp3);
            }
        }
        return min(dp1, min(dp2, dp3));
    }
};