class Solution {
public:
    string longestPalindrome(string s) {
        int longest=0;
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            //odd check
            int left=i-1;
            int right=i+1;
            while(left>=0&&right<n&&s[left]==s[right]){
                left--; right++;
            }
            if(right-left-1>longest){
                longest=max(longest, right-left-1);
                ans=s.substr(left+1, longest);
            }
            

            left=i;
            right=i+1;
            while(left>=0&&right<n&&s[left]==s[right]){
                left--; right++;
            }
            if(right-left-1>longest){
                longest=max(longest, right-left-1);
                ans=s.substr(left+1, longest);
            }
        }
        return ans;
    }
};