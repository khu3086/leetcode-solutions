class Solution {
public:
    int minSwaps(string s) {
        int n=s.length();
        int one=0;
        int zero=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') zero++;
            else one++;
        }
        int count1=0;
        int count2=0;
        int ans=INT_MAX;
        if(abs(one-zero)>1) return -1;
        if(zero>=one){
            for(int i=0;i<n;i+=2){
                //how many zero out of place
                if(s[i]=='1') count1++;
            }
            ans=count1;
        }
        if(zero<=one){
            for(int i=0;i<n;i+=2){
                //how many one out of place
                if(s[i]=='0') count2++;
            }
            ans=min(ans, count2);
        }
        return ans;
    }
};