class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int count=0;
        for(int i=0;i<n;i++){
            //odd 
            int left=i-1;
            int right=i+1;
            count++;//char itself

            while(left>=0&&right<n&&s[left]==s[right]){
                count++;
                left--;
                right++;
            }
            left=i;
            right=i+1;
            while(left>=0&&right<n&&s[left]==s[right]){
                count++;
                left--;
                right++;
            }
        }
        return count;
    }
};