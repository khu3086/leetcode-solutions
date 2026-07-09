class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=0;
        int maxsum=INT_MIN;
        for(auto c: nums){
            currsum=max(c, currsum+c);
            maxsum=max(maxsum, currsum);
        }
        return maxsum;
    }
};