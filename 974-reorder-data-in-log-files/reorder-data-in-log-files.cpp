class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string, string>> letter;
        vector<string> digit;
        for(auto log: logs){
            int pos=log.find(' ');
            if(log[pos+1]<='z'&&log[pos+1]>='a'){
                letter.push_back({log.substr(pos+1), log.substr(0, pos)});
            }
            else{
                digit.push_back(log);
            }
        }
        sort(letter.begin(), letter.end());
        vector<string> ans;
        for(auto l: letter){
            ans.push_back(l.second+" "+l.first);
        }
        for(auto d: digit) ans.push_back(d);
        return ans;
    }
};