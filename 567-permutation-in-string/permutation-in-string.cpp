class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        int left=0;
        int window=s1.size();
        int right=0;
        for(auto c: s1) mp1[c]++;
        for(int i=0;i<window;i++) mp2[s2[i]]++;
        if(mp1==mp2) return true;
        right=window;
        while(right<s2.size()){
            if(mp1!=mp2){
                mp2[s2[left]]--;
                if(mp2[s2[left]]==0) mp2.erase(s2[left]);
                left++;
                mp2[s2[right]]++;
                right++;
                if(mp1==mp2) return true;
            }
            else return true;
        }
        return false;
    }
};