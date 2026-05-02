class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> dp(n+1, 0);
        int count=0;
        for(int i=0;i<n+1;i++){
            if(i==2||i==5||i==6||i==9) dp[i]=2;
            if(i==0||i==1||i==8) dp[i]=1;
            // if i=3,4,7 dp=0
            int num1=0; int num2=0;
            if(i==10000){
                dp[i]=0;
            }
            else if(i<100){
                num1=dp[i/10];
                num2=dp[i%10];
            }
            else if(i<1000){
                num1=dp[i/100];
                num2=dp[i%100];
            }
            else if(i<10000){
                num1=dp[i/1000];
                num2=dp[i%1000];
            }
            if(num1==0||num2==0) dp[i]=0;
            else if(num1==2||num2==2) dp[i]=2;
            else dp[i]=1;
        }
        for(int i=1;i<n+1;i++){
            if(dp[i]==2) count++;
        }
        return count;
    }
};