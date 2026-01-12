class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n=nums.size();
        if(n==0) return 0;
        int left=0, right=nums.size()-1;
        while(left<n&&left<=right){
            if(nums[left]==val){
                swap(nums[left], nums[right]);
                right--;
            }
            else left++;
        }
        return left;
    }
};