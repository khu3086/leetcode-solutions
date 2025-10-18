class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()<=1) return s.length();
        unordered_set<char> seen;
        int maxlen=0;
        int left=0;
        for(int right=0;right<s.length();right++){
            if(seen.find(s[right])!=seen.end()){
                maxlen=max(maxlen, right-left);
            }
            while(seen.find(s[right])!=seen.end()){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            maxlen=max(maxlen, right-left+1);
        }
        return maxlen;
    }
};