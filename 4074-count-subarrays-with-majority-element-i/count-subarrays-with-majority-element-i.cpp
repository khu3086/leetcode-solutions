class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        //brute force n2
        int res=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=i;j<n;j++){
                if(nums[j]==target) count++;
                else count--;
                if(count>0) res++;
            }
        }
        return res;
    }
};