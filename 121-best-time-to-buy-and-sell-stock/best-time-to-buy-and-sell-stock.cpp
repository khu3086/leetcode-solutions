class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int currProfit=0;
        int maxProfit=INT_MIN;
        for(auto price: prices){
            minPrice=min(minPrice, price);
            currProfit=price-minPrice;
            maxProfit=max(maxProfit, currProfit);
        }
        return maxProfit;
    }
};