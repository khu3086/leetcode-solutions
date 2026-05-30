class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums[0]==0&&nums.size()==1) return true;
        int maxIdx=nums[0];
        for(int i=1;i<nums.size();i++){
            if(i>maxIdx) return false;
            maxIdx=max(maxIdx, i+nums[i]);
        }
        if(maxIdx<nums.size()-1) return false;
        return true;
    }
};