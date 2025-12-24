class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end());
        int count=0;
        for(auto x: apple) count+=x;
        int i=0;
        int n=capacity.size();
        while(i<=n&&count>0){
            i++;
            count-=capacity[n-i];
        }
        return i;
    }
};