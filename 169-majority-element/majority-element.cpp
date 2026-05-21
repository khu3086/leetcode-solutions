class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int vote=1;
        int maxEle=nums[0];
        for(int i=1;i<nums.size();i++){
            if(maxEle==nums[i]){
                vote++;
            }
            else{
                if(vote<=0){
                    maxEle=nums[i];
                    vote=0;
                }
                else vote--;
            }
        }
        return maxEle;
    }
};