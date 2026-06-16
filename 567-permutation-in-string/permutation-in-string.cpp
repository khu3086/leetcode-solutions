class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        unordered_map<char, int> mp1, mp2;
        for(auto c: s1) mp1[c]++;
        int window=s1.size();
        for(int i=0;i<window;i++) mp2[s2[i]]++;
        if(mp1==mp2) return true;
        for(int i=window;i<s2.size();i++){
            mp2[s2[i-window]]--;
            if(mp2[s2[i-window]]==0) mp2.erase(s2[i-window]);
            mp2[s2[i]]++;
            if(mp2==mp1) return true;
        }
        return false;
    }
};