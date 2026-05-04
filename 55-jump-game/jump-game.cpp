class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums[0]==0){
            if(nums.size()>1) return false;
            return true;
        }
        int n=nums.size();
        vector<bool> reach(n, false);
        reach[0]=true;
        for(int i=0;i<n;i++){
            if(!reach[i]) continue;
            for(int j=i+1;j<=i+nums[i];j++)
            if(j<n) reach[j]=true;
        }
        return reach[n-1];
    }
};