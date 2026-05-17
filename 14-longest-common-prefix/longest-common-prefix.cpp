class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string last=strs[0];
        for(auto str: strs){
            int i=0;
            int j=0;
            string temp="";
            while(i<str.size()&&j<last.size()&&str[i]==last[j]){
                temp+=str[i];
                i++; j++;
            }
            last=temp;
        }
        return last;
    }
};