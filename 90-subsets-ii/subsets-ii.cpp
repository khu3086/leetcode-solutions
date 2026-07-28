class Solution {
public:
    void subset(vector<vector<int>>& ans, vector<int>& nums, vector<int> curr, int i){
        
        if(i==nums.size()){
            ans.push_back(curr);
            return;
        }
        // Take nums[i]
        curr.push_back(nums[i]);
        subset(ans, nums, curr, i + 1);
        curr.pop_back();

        // Don't take nums[i]
        // Skip all duplicates of nums[i]
        int j = i + 1;
        while(j < nums.size() && nums[j] == nums[i]) {
            j++;
        }

        subset(ans, nums, curr, j);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> curr;

        subset(ans, nums, curr, 0);

        return ans;
    }
};