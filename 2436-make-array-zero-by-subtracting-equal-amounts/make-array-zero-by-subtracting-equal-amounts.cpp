class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        //find smallest nonzero ele
        //find largest ele
        // 2 3 5 7 (range is 2 to 7) -> inke remnants ko store karo
        int ans=0;
        int i=0;
        int count=0;
        for(i=0;i<nums.size();i++){
            if(nums[i]!=0&&ans==0){
                ans=nums[i];
                count++;
                continue;
            }
            if(nums[i]-ans>0){
                count++;
                ans+=nums[i]-ans;
            }
        }
        return count;
    }
};