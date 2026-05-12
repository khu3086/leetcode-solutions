class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](vector<int>& a, vector<int>& b) {
            return a[1] - a[0] > b[1] - b[0];
        });
        int loan=0;
        int start=tasks[0][1];
        int balance=start-tasks[0][0];
        for(int i=1;i<tasks.size();i++){
            if(balance<tasks[i][1]){
                loan+=(tasks[i][1]-balance);
                balance=tasks[i][1];
            }
            balance-=tasks[i][0];
        }
        return start+loan;
    }
};