class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.length()<=1) return s.length();
        unordered_map<char, int> seen;
        char maxChar=0;
        int maxNum=0;
        int left=0;
        int maxlen=0;
        for(int right=0;right<s.length();right++){
            if(maxChar==0){
                seen[s[right]]++;
                maxNum++;
                maxChar=s[right];
                continue;
            }
            seen[s[right]]++;
            if(seen[s[right]]>maxNum){
                maxChar=s[right];
                maxNum=seen[s[right]];
            }
            int uniq=right-left+1-maxNum;
            while(uniq>k){
                seen[s[left]]--;
                if(seen[s[left]]==0) seen.erase(s[left]);
                left++;
                uniq=right-left+1-maxNum;
            }
            maxlen=max(maxlen, right-left+1);
        }
        return maxlen;
    }
};