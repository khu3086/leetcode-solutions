class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> st;
        int i=0;
        int maxlen=0;
        for(int j=0;j<s.length();j++){
            while(st.find(s[j])!=st.end()){
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            maxlen=max(maxlen, j-i+1);
        }
        return maxlen;
    }
};