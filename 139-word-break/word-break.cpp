class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len=s.length();
        vector<bool> dp(len+1, false);
        dp[0]=true;
        for(int i=0;i<=len;i++){
            for(auto word: wordDict){
                if(i>=word.length()){
                    if(s.substr(i-word.length(), word.length())==word){
                        dp[i] =dp[i]||dp[i - word.length()];
                    }
                }
            }
        }
        return dp[len];
    }
};