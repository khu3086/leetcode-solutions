class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k<=0) return false;
        int n=nums.size();
        unordered_set<int> seen;
        for(int i=0;i<n;i++){
            if(seen.find(nums[i])!=seen.end()) return true;
            seen.insert(nums[i]);
            if(seen.size()>k){
                seen.erase(nums[i-k]);
            }
        }
        return false;
    }
};