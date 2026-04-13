class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<bool> dp(n+1, false);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(auto word: wordDict){
                if(i>=word.length()){
                    string tmp=s.substr(i-word.length(), word.length());
                    if(tmp==word){
                        dp[i]=dp[i-word.length()]||dp[i];
                    }
                }
            }
        }
        return dp[n];
    }
};