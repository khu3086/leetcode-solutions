class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int currsum=0;
        int left=0;
        int minlen=INT_MAX;
        for(int right=0;right<nums.size();right++){
            currsum+=nums[right];
            while(currsum>=target){
                minlen=min(minlen, right-left+1);
                if(currsum-nums[left]<target) break;
                currsum-=nums[left];
                left++;
            }
        }
        if(minlen==INT_MAX) return 0;
        return minlen;
    }
};