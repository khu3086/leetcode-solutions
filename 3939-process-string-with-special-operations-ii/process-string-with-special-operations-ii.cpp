class Solution {
    typedef long long ll;
public:
    char processStr(string s, ll k) {
        int n = s.size();
        ll len = 0;

        for (auto& ch : s) {
            if (ch == '*')
                len = max(len - 1, 0LL);
            else if (ch == '#')
                len *= 2;
            else if (ch != '%')
                len++;
        }

        if (k >= len) return '.';

        
        for(int i=n-1;i>=0;i--){
            int c=s[i];
            if(c=='*'){
                len++;
            }
            else if(c=='#'){
                if(k>=len/2) k-=len/2;
                len/=2;
            }
            else if(c=='%'){
                k=len-k-1;
            }
            else{
                if(len-1==k) return s[i];
                len--;
            }
        }
        return '.';
    }
};