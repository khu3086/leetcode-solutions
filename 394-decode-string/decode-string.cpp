class Solution {
public:
    string helper(string& s, int& i){
        string ans="";
        while(i<s.size()&&s[i]!=']'){
            if(isalpha(s[i])){
                ans+=s[i];
                i++;
            }
            if(isdigit(s[i])){
                string temp="";
                while(i<s.size()&&isdigit(s[i])){
                    temp+=s[i];
                    i++;
                }
                i++;
                string middle=helper(s, i);
                int num=stoi(temp);
                while(num){
                    ans+=middle;
                    num--;
                }
            }
            
        }
        if(i < s.size() && s[i] == ']')
        i++;  
        return ans;
    }
    string decodeString(string s) {
        int i=0;
        string ans=helper(s, i);
        return ans;
    }
};