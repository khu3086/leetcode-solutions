class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        int n=s.length();
        for(int i=0;i<n;i++){
            mp[s[i]]=i;
        }
        int left=0;
        int right=0;
        vector<int> ans;
        while(right<n){
            int lastCheck = mp[s[right]];
            while(right<=lastCheck&&right<n){
                
                lastCheck=max(lastCheck, mp[s[right]]);
                right++;
            }
            ans.push_back(right-left);
            left=right;
        }
        return ans;
    }
};