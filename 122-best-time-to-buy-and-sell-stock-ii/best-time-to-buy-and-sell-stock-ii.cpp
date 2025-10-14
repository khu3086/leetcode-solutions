class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left=0;
        int right=1;
        int n=prices.size();
        int totalprofit=0;
        while(right<n){
            while(right<n&&prices[right-1]<=prices[right]) right++;
            totalprofit+=prices[right-1]-prices[left];
            left=right;
            right++;
        }
        return totalprofit;
    }
};