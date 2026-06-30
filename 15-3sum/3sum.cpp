class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++){
            if(i>0&&nums[i-1]==nums[i]) continue;
            int low=i+1;
            int high=n-1;
            while(low<high){
                int sum=nums[low]+nums[high]+nums[i];
                if(sum==0){
                    ans.push_back({nums[i], nums[low], nums[high]});
                    while(low<high&&nums[low]==nums[low+1]) low++;
                    while(low<high&&nums[high]==nums[high-1]) high--;
                    low++; high--;
                }
                else if(sum<0) low++;
                else high--;
            }
        }
        return ans;
    }
};