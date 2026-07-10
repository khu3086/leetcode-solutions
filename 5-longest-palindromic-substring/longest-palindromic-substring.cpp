class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int maxlen=0;
        string ans="";
        for(int i=0;i<n;i++){
            int left=i-1;
            int right=i+1;
            while(left>=0&&right<n&&s[left]==s[right]){
                left--;
                right++;
            }
            if(right-left-1>maxlen){
                maxlen=right-left-1;
                ans=s.substr(left+1, maxlen);
            }
             left=i;
             right=i+1;
            while(left>=0&&right<n&&s[left]==s[right]){
                left--;
                right++;
            }
            if(right-left-1>maxlen){
                maxlen=right-left-1;
                ans=s.substr(left+1, maxlen);
            }
        }
        return ans;
    }
};