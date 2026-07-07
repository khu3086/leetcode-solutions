class Solution {
public:
    int calculateDays(vector<int>& weights, int capa){
        int currsum=0;
        int days=1;
        for(auto x: weights){
            if(currsum+x>capa){
                days++;
                currsum=x;
            }
            else{
                currsum+=x;
            }
        }
        return days; 
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int high=INT_MIN;
        int low=0;
        for(auto w: weights) {high=max(w, high); low+=w;}
        swap(low, high);
        while(low<=high){
            int mid=low+(high-low)/2;
            int day=calculateDays(weights, mid);
            if(day>days){
                low=mid+1;
            }
            else high=mid-1;
        }
        return low;
    }
};