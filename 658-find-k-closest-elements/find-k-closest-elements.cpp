class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> pq;
        for(int i=0;i<arr.size();i++){
            int dist=abs(arr[i]-x);
            pq.push({dist, arr[i]});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(pq.size()){
            auto it=pq.top();
            pq.pop();
            ans.push_back(it.second);
        }
        sort(ans.begin(), ans.end());
        return ans;

    }
};