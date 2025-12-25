class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        int selected=0;
        long long totalHappiness=0;
        int n=happiness.size();
        while(selected!=k){
            if(happiness[n-selected-1]-selected>=0)
            totalHappiness+=happiness[n-selected-1]-selected;
            selected++;
        }
        return totalHappiness;
    }
};