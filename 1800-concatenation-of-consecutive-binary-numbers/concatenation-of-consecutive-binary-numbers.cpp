class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans=0;
        long long mod=1000000007;
        for(int i=1;i<=n;i++){
            int digpos=(int)log2(i)+1;  // bit length of i
            ans=((ans<<digpos)|i)%mod;
        }
        return (int)ans;
    }
};