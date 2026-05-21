class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix(n, 0);
        for(int i=0;i<n;i++){
            if(i==0) prefix[0]=nums[0];
            else{
                prefix[i]=nums[i]+prefix[i-1];
            }
        }
        int ans=0;
        unordered_map<int, int> mp;
        for(auto p: prefix){
            if(p==k){
                ans++;
            }
            if(mp.find(p-k)!=mp.end()){
                ans+=mp[p-k];
            }
            mp[p]++;
        }
        return ans;
    }
};