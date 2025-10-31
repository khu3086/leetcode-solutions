class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]++;
        }
        for(int i=0;i<n;i++){
            int absIdx=abs(nums[i])-1;
            nums[absIdx]*=-1;
        }
        vector<int> ans;
        for(int i=0;i<n-2;i++){
            
            if(nums[i]>0) ans.push_back(i);
        }
        return ans;
    }
};