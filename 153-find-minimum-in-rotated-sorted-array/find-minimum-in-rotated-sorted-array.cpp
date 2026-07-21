class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int ans = nums[low];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<nums[high]){
                ans = min(ans, nums[mid]);
                high=mid;
            }else{
                low=mid+1;
                ans = min(ans, nums[high]);
            }
        }
        return nums[high];
    }
};