class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int diff=0;
        int total=0;
        int idx=0;
        int tank=0;
        for(int i=0;i<cost.size();i++){
            diff=gas[i]-cost[i];
            tank+=diff;
            if(tank<0){
                idx=(i+1)%cost.size();
                tank=0;
            }
            total+=diff;
        }
        if(total<0) return -1;
        return idx;
    }
};