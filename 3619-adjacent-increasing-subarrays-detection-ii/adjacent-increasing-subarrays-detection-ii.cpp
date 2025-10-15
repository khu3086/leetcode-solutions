class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return 0;
        if(n==2) return 1;
        int left=0;
        int right=1;
        int prevlen=0;
        int k=0;
        while(right<n){
            while(right<n&&nums[right-1]<nums[right]) right++;
            int currlen=right-left;
            left=right;
            right++;
            int minlen=min(prevlen, currlen);
            k=max(k, currlen/2);
            k=max(k, minlen);
            prevlen=currlen;
        }
        return k;
    }
};