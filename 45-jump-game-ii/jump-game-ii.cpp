class Solution {
public:
    int jump(vector<int>& nums) {
         if(nums.size()==1) return 0;
        int farthest=0;
        int jump=0;
        int currEnd=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            farthest=max(farthest, nums[i]+i);
            if(currEnd==i){
                jump++;
                currEnd=farthest;
            }
        }
        return jump;
    }
};