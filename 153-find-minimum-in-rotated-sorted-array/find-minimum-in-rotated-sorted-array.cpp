class Solution {
public:
    int findMin(vector<int>& nums) {
        int numRotate=0;
        while(numRotate+1<nums.size()&&nums[numRotate]<nums[numRotate+1]) numRotate++;
        return nums[(numRotate+1)%nums.size()];
    }
};