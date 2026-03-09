class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int mod = 1000000007;
        vector<vector<int>> dp0(zero+1, vector<int>(one+1, 0));
        vector<vector<int>> dp1(zero+1, vector<int>(one+1, 0));

        for(int i=1;i<=min(limit, zero); i++) dp0[i][0]=1;
        for(int i=1;i<=min(limit, one); i++) dp1[0][i]=1;

        for(int i=1;i<=zero;i++){
            for(int j=1;j<=one;j++){
                for(int k=1;k<=min(i, limit);k++)
                dp0[i][j]=(dp0[i][j]+dp1[i-k][j])%mod;
                for(int k=1;k<=min(j, limit);k++)
                dp1[i][j]=(dp1[i][j]+dp0[i][j-k])%mod;
            }
        }

        return (dp0[zero][one]+dp1[zero][one])%mod;
    }
};