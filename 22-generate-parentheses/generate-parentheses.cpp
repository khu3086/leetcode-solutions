class Solution {
public:
    void generate(vector<string>& ans, int open, int close, string& str, int n){
        if(str.length()==2*n){
            ans.push_back(str);
            return;
        }
        if(open<n){
            str+='(';
            generate(ans, open+1, close, str, n);
            str.pop_back();
        }
        if(close<open){
            str+=')';
            generate(ans, open, close+1, str, n);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        generate(ans, 0, 0, temp, n);
        return ans;
    }
};