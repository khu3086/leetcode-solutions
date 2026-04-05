class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return n;
        int one=1;
        int two=1;
        int ans=0;
        for(int i=2;i<=n;i++){
            ans=one+two;
            one=two;
            two=ans;
        }
        return ans;
    }
};