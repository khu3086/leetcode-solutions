class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest=0;
        int n=nums.size();
        int jump=0;
        int currEnd=0;
        if(n==1) return 0;
        for(int i=0;i<n-1;i++){
            farthest=max(farthest, i+nums[i]);
            if(i==currEnd){
                jump++;
                currEnd=farthest;
            }
        }
        return jump;
    }
};