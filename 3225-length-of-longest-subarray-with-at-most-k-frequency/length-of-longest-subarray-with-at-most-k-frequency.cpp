class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int j=0;
        int n=nums.size();
        unordered_map<int, int> mp;
        int maxlen=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            while(j<n&&mp[nums[i]]>k){
                mp[nums[j]]--;
                if(mp[nums[j]]==0) mp.erase(nums[j]);
                j++;
            }
            maxlen=max(maxlen, i-j+1);
        }
        return maxlen;
    }
};