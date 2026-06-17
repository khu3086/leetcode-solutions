class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i=0;
        unordered_set<int> st;
        for(int j=0;j<nums.size();j++){
            if(j-i>k){
                st.erase(nums[i]);
                i++;
            }
            if(st.find(nums[j])!=st.end()) return true;
            st.insert(nums[j]);
        }
        return false;
    }
};