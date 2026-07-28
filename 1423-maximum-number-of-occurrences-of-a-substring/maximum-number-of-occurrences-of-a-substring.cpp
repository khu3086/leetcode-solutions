class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<char, int> mp;
        unordered_map<string, int> strs;
        int maxOccur=0;
        int j=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while(mp.size()>maxLetters){
                mp[s[j]]--;
                if(mp[s[j]]==0) mp.erase(s[j]);
                j++;
            }
            int len=i-j+1;
            if(len>=minSize){
                string sub = s.substr(i - minSize + 1, minSize);
                strs[sub]++;
                maxOccur=max(maxOccur, strs[sub]);
            }
        }
        return maxOccur;
    }
};