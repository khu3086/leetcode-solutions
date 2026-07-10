class Solution {
public:
    string helper(string s, int& i){
        string ans="";
        while(i<s.length()){
            if(s[i]>='0'&&s[i]<='9'){
                int num=0;
                while(s[i]!='['){
                    num=num*10+s[i]-'0';
                    i++;
                }
                i++;
                string temp=helper(s, i);
                i++;
                while(num){
                    ans+=temp;
                    num--;
                }
            }
            else if(s[i]==']') return ans;
            else {ans+=s[i];
            i++;}
        }
        return ans;
    }
    string decodeString(string s) {
        int idx=0;
        string ans=helper(s, idx);
        return ans;
    }
};