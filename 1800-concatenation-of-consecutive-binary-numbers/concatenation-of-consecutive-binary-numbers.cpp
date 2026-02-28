class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans=0;
        long long mod=1000000007;
        long long powadd=1;
        for(int i=n;i>=1;i--){
            int bits=(int)log2(i)+1;
            ans=(ans+((long long)i%mod*powadd)%mod)%mod;
            powadd=powadd*(long long)pow(2,bits)%mod;
        }
        return (int)ans;
    }
};