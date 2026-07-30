class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int ans=0;
        unordered_map<char, int> mp;
        for(int i=0;i<n;i++){
            int push=mp.size()/8+1;
            if(mp.find(word[i])==mp.end()){
                mp[word[i]]=push;
            }
            ans+=mp[word[i]];
        }
        return ans;
    }
};