class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int cnt=1;
        for(int j=1;j<nums.size();j++){
            if(nums[j-1]!=nums[j]){
                cnt++;
                i++;
                nums[i]=nums[j];
            }
        }
        return cnt;
    }
};