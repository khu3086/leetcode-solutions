class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total=0;
        for(int i=0;i<prices.size();i++){
            if(i>0){
                int diff=prices[i]-prices[i-1];
                if(diff>0) total+=diff;
            }
        }
        return total;
    }
};