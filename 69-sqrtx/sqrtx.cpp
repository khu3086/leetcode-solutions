class Solution {
public:
    int mySqrt(int x) {
        int high=x;
        int low=1;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long xx=(long long)x;
            if(mid*mid==xx) return mid;
            else if(mid*mid<xx) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};