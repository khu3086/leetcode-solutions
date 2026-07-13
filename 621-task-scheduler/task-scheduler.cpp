class Solution {
public:
    int leastInterval(vector<char>& task, int n) {
        unordered_map<char, int> mp;
        int maxfreq=0;
        for(int i=0;i<task.size();i++){
            mp[task[i]]++;
            maxfreq=max(maxfreq, mp[task[i]]);
        } 
        int count=0;
        for(auto m: mp){
            if(m.second==maxfreq) count++;
        }
        int ans=((n+1)*(maxfreq-1))+count;
        int len=task.size();
        return max(ans, len);
    }
};