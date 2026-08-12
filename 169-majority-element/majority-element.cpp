class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=nums[0];
        int vote=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==ele){
                vote++;
            }
            else{
                vote--;
                if(vote==0){
                    ele=nums[i];
                    vote=1;
                }
            }
        }
        return ele;
    }
};