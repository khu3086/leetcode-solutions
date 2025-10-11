class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix;
        prefix.push_back(0);
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            prefix.push_back(prefix[i]+nums[i]);
        }
        int ans=0;
        n=prefix.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(prefix[j]-prefix[i]==k)
                ans++;
            }
        }
        return ans;
    }
};