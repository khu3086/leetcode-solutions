class Solution {
public:
    long calculate(vector<int>& piles, int speed){
        long ans = 0;
        for(auto p : piles){
            ans += p / speed;
            if(p % speed != 0) ans++;   // Fix: check p, not ans
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxSpeed = 0;
        for(auto p : piles) maxSpeed = max(maxSpeed, p);

        int low = 1;
        int high = maxSpeed;
        int mid;
        int ans = maxSpeed;

        while(low <= high){
            mid = low + (high - low) / 2;
            long hr = calculate(piles, mid);

            if(hr <= h){
                ans = mid;      // store possible answer
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;             // return stored answer
    }
};