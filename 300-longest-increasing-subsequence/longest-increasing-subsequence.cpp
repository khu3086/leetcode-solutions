class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tail;
        for(int i=0;i<nums.size();i++){
            auto it=lower_bound(tail.begin(), tail.end(), nums[i]);
            if(it==tail.end()){
                tail.push_back(nums[i]);
            }
            else{
                *it=nums[i];
            }
        }
        return tail.size();
    }
};