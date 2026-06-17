class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int currsum=0;
        int minLength=INT_MAX;
        int prev=0;
        for(int j=0;j<nums.size();j++){
            currsum+=nums[j];
            while(i<=j&&currsum>=target){
                prev=currsum;
                currsum-=nums[i];
                i++;
                if(currsum<target){
                minLength=min(minLength, j-i+1);
            }
            }
        }
        if(minLength==INT_MAX) return 0;
        return minLength+1;
    }
};