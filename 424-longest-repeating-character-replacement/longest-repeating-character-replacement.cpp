class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> freq;
        int i=0;
        int res=0;
        int maxfreq=0;
        for(int j=0;j<s.length();j++){
            freq[s[j]]++;
            maxfreq=max(maxfreq, freq[s[j]]);
            while(j-i+1-maxfreq>k){
                freq[s[i]]--;
                i++;
            }
            res=max(res, j-i+1);
        }
        return res;
    }
};