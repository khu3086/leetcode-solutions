class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left=0;
        int right=0;
        int maxlen=0;
        while(right<s.length()){
            while(st.find(s[right])!=st.end()&&left<=right){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            right++;
            maxlen=max(maxlen, right-left);
        }
        return maxlen;
    }
};