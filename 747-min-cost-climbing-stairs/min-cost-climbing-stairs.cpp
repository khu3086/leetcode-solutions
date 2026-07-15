class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int first=0;
        int second=0;
        int ans=INT_MAX;
        for(int i=2;i<=cost.size();i++){
            ans=min(first+cost[i-2], second+cost[i-1]);
            first=second;
            second=ans;
        }
        return ans;
    }
};