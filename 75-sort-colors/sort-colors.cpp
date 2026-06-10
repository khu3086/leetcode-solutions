class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start=0;
        int last=nums.size()-1;
        int middle=0;
        while(middle<=last){
            if(nums[middle]==1) middle++;
            else if(nums[middle]==0){
                swap(nums[middle], nums[start]);
                middle++;
                start++;
            }
            else{
                swap(nums[middle], nums[last]);
                last--;
            }
        }
    }
};