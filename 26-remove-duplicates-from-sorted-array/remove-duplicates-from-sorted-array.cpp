class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left=0, right=1;
        int n=nums.size();
        int low=0;
        while(right<n){
            while(right<n&&nums[left]==nums[right]) right++;
            if(right<n)
            nums[++low]=nums[right];
            left=right;
            right++;
        }
        return low+1;
    }
};