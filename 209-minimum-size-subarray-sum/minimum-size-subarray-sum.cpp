class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int currsum=0;
        int left=0;
        int minlen=INT_MAX;
        for(int right=0;right<nums.size();right++){
            currsum+=nums[right];
            // shrink window while it's valid
            while (currsum >= target) {
                minlen = min(minlen, right - left + 1);
                currsum -= nums[left];
                left++;
            }
        }
        return minlen==INT_MAX?0:minlen;
    }
};