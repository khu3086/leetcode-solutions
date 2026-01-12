class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int dx=0;
        int dy=0;
        int ans=0;
        int n=points.size();
        for(int i=0;i<n-1;i++){
            dx=abs(points[i][0]-points[i+1][0]);
            dy=abs(points[i][1]-points[i+1][1]);
            int additive=min(dx, dy);
            int maxitive=max(dx, dy);
            if(additive==maxitive) ans+=additive;
            else{
                ans+=additive;
                ans+=maxitive-additive;
            }
        }
        return ans;
    }
};