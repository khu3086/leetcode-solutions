class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto num: nums) mp[num]++;
        auto cmp=[](pair<int, int> a, pair<int, int> b){
            if(a.first==b.first) return a.second>b.second;
            return a.first>b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq (cmp);
        for(auto m: mp){
            pq.push({m.second, m.first});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};