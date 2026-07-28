class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.length();
        if(n<=2) return s;
        string temp="";
        if(n%2==0){
            temp=s.substr(0, n/2);
            sort(temp.begin(), temp.end());
            string temp2=temp;
            reverse(temp2.begin(), temp2.end());
            temp+=temp2;
        }
        else{
            temp=s.substr(0, n/2);
            sort(temp.begin(), temp.end());
            string temp2=temp;
            reverse(temp2.begin(), temp2.end());
            temp+=s[n/2];
            temp+=temp2;
        }
        return temp;
    }
};