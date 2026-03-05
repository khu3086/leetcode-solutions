class Solution {
public:
    int minOperations(string s) {
        int ans=0;
        int n=s.length();
        for(int i=0;i<n-1;i=i+2){
            if(s[i]-'0'!=1) ans++;
            if(s[i+1]-'0'!=0) ans++;
        }
        if(n%2 && (s[n-1]-'0'!=1)) ans++;
        return min(ans, n-ans);

        }
};