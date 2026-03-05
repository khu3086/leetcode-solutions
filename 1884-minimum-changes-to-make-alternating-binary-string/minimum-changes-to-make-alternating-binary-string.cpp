class Solution {
public:
    int minOperations(string s) {
        int ans1=0, ans2=0;
        int n=s.length();
        for(int i=0;i<n-1;i=i+2){
            if(s[i]-'0'!=1) ans1++;
            if(s[i+1]-'0'!=0) ans1++;
        }
        if(n%2 && (s[n-1]-'0'!=1)) ans1++;
        for(int i=0;i<n-1;i=i+2){
            if(s[i]-'0'!=0) ans2++;
            if(s[i+1]-'0'!=1) ans2++;
        }
        if(n%2 && (s[n-1]-'0'!=0)) ans2++;
        return min(ans1, n-ans1);

        }
};