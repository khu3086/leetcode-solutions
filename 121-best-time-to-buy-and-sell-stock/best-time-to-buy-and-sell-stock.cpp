class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxProfit=INT_MIN;
        for(int i=0;i<prices.size();i++){
            minPrice=min(minPrice, prices[i]);
            int currPrice=prices[i]-minPrice;
            maxProfit=max(maxProfit, currPrice);
        }
        return maxProfit;
    }
};