class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pair<int, int>> heap;
        for(auto vec: boxTypes){
            heap.push({vec[1], vec[0]});
        }
        int count=0;
        int sz=truckSize;
        while(!heap.empty()&&sz){
            auto [unit, num]=heap.top();
            heap.pop();
            int take=min(sz, num);
            sz-=take;
            count+=take*unit;
        }
        return count;
    }
};