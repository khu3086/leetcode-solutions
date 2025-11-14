class Solution {
public:
    int calculateHrs(vector<int>& piles, int s){
        int ans=0;
        for(auto x: piles){
            ans+=x/s;
            if(x%s) ans++;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            int mid = low + (high - low) / 2;
            int hrs = calculateHrs(piles, mid);

            if (hrs <= h) {
                high = mid;        // try smaller speed
            } else {
                low = mid + 1;     // need faster speed
            }
        }
        return low;
    }
};