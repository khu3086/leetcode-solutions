class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return n;
        if(n<=2) return 1;
        int one=0;
        int two=1;
        int three=1;
        int ans=0;
        for(int i=3;i<=n;i++){
            ans=one+two+three;
            one=two;
            two=three;
            three=ans;
        }
        return ans;
    }
};