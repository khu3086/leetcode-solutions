class Solution {
public:
    bool checkOnesSegment(string s) {
        int pos=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            int num=s[i]-'0';
            if(num==0){
                if(pos==0) pos=i;
            }
            else{
                if(pos!=0) return false;
            }
        }
        return true;
    }
};