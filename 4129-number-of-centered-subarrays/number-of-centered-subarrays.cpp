class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            int subsum=0;
            unordered_set<int> st;
            for(int j=i;j<n;j++){
                st.insert(nums[j]);
                subsum+=nums[j];
                if(st.find(subsum)!=st.end()) res++;
            }
        }
        return res;
    }
};