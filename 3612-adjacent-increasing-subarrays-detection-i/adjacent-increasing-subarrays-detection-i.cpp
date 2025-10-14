class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<=1) return false;
        int left=0; int right=1;
        int lastlen=0;
        if(k==1) return true;
        while(right<n){
            while(right<n&&nums[right-1]<nums[right]){
                right++;
            }
            int currlen=right-left;
            left=right;
            right++;
            if(currlen>=2*k) return true;
            if(lastlen>=k&&currlen>=k) return true;
            lastlen=currlen;
        }
        return false;
    }
};