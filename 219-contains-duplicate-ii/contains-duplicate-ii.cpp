class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //if(k<=1) return false;
        unordered_set<int> seen;
        int left=0;
        for(int right=0;right<nums.size();right++){
            while(right-left>k){
                seen.erase(nums[left]);
                left++;
            }
            if(seen.find(nums[right])!=seen.end()) return true;
            seen.insert(nums[right]);
        }
        return false;
    }
};