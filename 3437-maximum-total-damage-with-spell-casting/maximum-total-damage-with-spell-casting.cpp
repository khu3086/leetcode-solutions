class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, long long> freq;
        for(auto x: power) freq[x]++;
        vector<int> powerArr;
        for(auto x: freq) powerArr.push_back(x.first);
        sort(powerArr.begin(), powerArr.end());
        int n=powerArr.size();
        vector<long long> dp(n);
        dp[0]=freq[powerArr[0]]*powerArr[0];
        for(int i=1;i<n;i++){
            long long take=freq[powerArr[i]]*powerArr[i];
            int prev=upper_bound(powerArr.begin(), powerArr.begin()+i, powerArr[i]-3)-powerArr.begin()-1;
            if(prev>=0) take+=dp[prev];
            dp[i]=max(dp[i-1], take);
        }
        return dp[n-1];
    }
};