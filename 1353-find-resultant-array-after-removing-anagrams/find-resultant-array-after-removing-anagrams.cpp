class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int n=words.size();
        ans.push_back(words[0]);
        for(int i=1;i<n;i++){
            string last=ans[ans.size()-1];
            sort(last.begin(), last.end());
            string incoming=words[i];
            sort(incoming.begin(), incoming.end());
            if(last!=incoming) ans.push_back(words[i]);
        }
        return ans;
    }
};