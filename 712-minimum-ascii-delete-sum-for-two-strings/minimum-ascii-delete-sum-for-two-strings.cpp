class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int maxSum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(s1[i]==s2[j]){
                    dp[i+1][j+1]=dp[i][j]+s1[i];
                }
                else{
                    dp[i+1][j+1]=max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        int sum1=0, sum2=0;
        for(char c: s1) sum1+=c;
        for(char c: s2) sum2+=c;
        return sum1+sum2-2*dp[m][n];
    }
};