class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxProfit= INT_MAX;
        int currProfit=0;
        int total=0;
        for(auto price: prices){
            minPrice=min(minPrice, price);
            currProfit=price-minPrice;
            if(currProfit>0) {total+=currProfit; minPrice=price;}
        }
        return total;
    }
};