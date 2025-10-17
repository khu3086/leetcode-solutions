class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k=s1.size(); //establishing window size
        int left=0;
        unordered_map<char, int> mp1, mp2;
        for(auto x: s1) mp1[x]++;
        for(int right=0;right<s2.size();right++){
            mp2[s2[right]]++;
            while(right-left+1>k){
                mp2[s2[left]]--;
                if(mp2[s2[left]]==0) mp2.erase(s2[left]);
                left++;
            }
            if(mp1==mp2) return true;
        }
        return false;
    }
};