class Solution {
public:
    bool validPalindrome(string s) {
        int len=s.length();
        int left=0, right=len-1;
        int count1=1;
        while(left<right){
            if(s[left]!=s[right]) {count1--; right--; continue;}
            left++;
            right--;
        }
        left=0; right=len-1;
        int count2=1;
        while(left<right){
            if(s[left]!=s[right]) {count2--; left++; continue;}
            left++;
            right--;
        }
        if(count1>=0||count2>=0) return true;
        return false;
    }
};