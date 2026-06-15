class Solution {
public:
    bool isPalindrome(string s) {
        int left=0;
        int right=s.length()-1;
        while(right>left){
            if(!isalnum(s[left])){
                left++; continue;
            }
            if(!isalnum(s[right])){
                right--; continue;
            }
            if(tolower(s[left])!=tolower(s[right])) return false;
            left++; right--;
        }
        return true;
    }
};