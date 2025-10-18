class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int currsum=0;
        int left=0;
        int minlen=INT_MAX;
        for(int right=0;right<nums.size();right++){
            currsum+=nums[right];
            if(currsum<target) continue;
            minlen=min(minlen, right-left+1);
            while(currsum>=target){
                currsum-=nums[left];
                left++;
                if(currsum>=target) minlen=min(minlen, right-left+1);
            }
            //minlen=min(minlen, right-left+1);
        }
        return minlen==INT_MAX?0:minlen;
    }
};