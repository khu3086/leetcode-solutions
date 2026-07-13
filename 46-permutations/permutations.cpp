class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, int curr, vector<int> currArr){
        if(curr==nums.size()) {
            ans.push_back(currArr);
            return;
        }
        for(int i=curr;i<currArr.size();i++){
            swap(currArr[i], currArr[curr]);
            backtrack(nums, ans, curr+1, currArr);
            swap(currArr[i], currArr[curr]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> currArr=nums;
        backtrack(nums, ans, 0, currArr);
        return ans;
    }
};