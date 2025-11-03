class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int ans=0;
        int i=0;
        while(i<n){
            int maxtime=neededTime[i];
            int colorsum=neededTime[i];
            int j=i+1;
            while(j<n&&colors[i]==colors[j]){
                maxtime=max(maxtime, neededTime[j]);
                colorsum+=neededTime[j];
                j++;
            }
            int excesssum=colorsum-maxtime;
            ans+=excesssum;
            i=j;
        }
        return ans;
    }
};