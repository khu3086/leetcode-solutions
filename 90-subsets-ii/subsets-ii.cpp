class Solution {
public:
    void recurse(vector<vector<int>>& ans, int i, int n, vector<int> nums, vector<int> curr){
        if(i>n) return;
        if(i==n){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        recurse(ans, i + 1, n, nums, curr);
        curr.pop_back();

        // Don't take nums[i]
        int j = i + 1;
        while(j < n && nums[j] == nums[i])
            j++;

        recurse(ans, j, n, nums, curr);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        int i=0;
        vector<int> curr;
        recurse(ans, i, nums.size(), nums, curr);
        return ans;
    }
};