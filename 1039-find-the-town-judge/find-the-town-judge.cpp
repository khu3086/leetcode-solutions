class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1&&trust.size()==0) return n; 
        unordered_map<int, int> mp;
        unordered_map<int, int> mp2;
        unordered_set<int> candidate;
        for(int i=0;i<trust.size();i++){
            mp[trust[i][0]]++;
            mp2[trust[i][1]]++;
            candidate.insert(trust[i][0]);
            candidate.insert(trust[i][1]);
        }
        for(auto x: candidate){
            if(mp.find(x)!=mp.end()) continue;
            if(mp2[x]==n-1) return x;
        }
        return -1;
    }
};