class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.length();
        if(n<=2) return s;
        if(n%2)
        {sort(s.begin(), s.begin()+n/2);
        sort(s.begin()+n/2+1, s.end());
        reverse(s.begin()+n/2+1, s.end());}
        else{
            sort(s.begin(), s.begin()+n/2);
        sort(s.begin()+n/2, s.end());
        reverse(s.begin()+n/2, s.end());
        }
        return s;
    }
};