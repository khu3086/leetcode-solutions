class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<char, int> st;
        int n=s.size();
        int j=0;
        int count=0;
        int maxOccur=0;
        unordered_map<string, int> mp;
        for(int i=0;i<n;i++){
            st[s[i]]++;

            while (st.size() > maxLetters) {
                st[s[j]]--;

                if (st[s[j]] == 0)
                    st.erase(s[j]);

                j++;
            }
            int currLen=i-j+1;
            if (i - j + 1 >= minSize) {
                string sub = s.substr(i - minSize + 1, minSize);

                mp[sub]++;
                maxOccur = max(maxOccur, mp[sub]);
            }
        }
        return maxOccur;
    }
};