class Solution {
public:
    void recurse(vector<vector<int>>& ans, int i, int n,
                 vector<int> nums, vector<int> curr) {

        ans.push_back(curr);

        int j = i;

        while(j < n) {
            curr.push_back(nums[j]);

            recurse(ans, j + 1, n, nums, curr);

            curr.pop_back();

            while(j + 1 < n && nums[j] == nums[j + 1])
                j++;

            j++;
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        int i = 0;
        vector<int> curr;

        recurse(ans, i, nums.size(), nums, curr);

        return ans;
    }
};