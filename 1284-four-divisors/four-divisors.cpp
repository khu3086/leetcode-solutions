class Solution {
public:
    int sumDivisors(int num){
        int x= num;
        int count = 0;
            int sum = 0;

        for (int i = 1; i * i <= x; i++) {
                if (x % i == 0) {
                    int j = x / i;

                    // Count i
                    count++;
                    sum += i;

                    // Count j if it's different
                    if (i != j) {
                        count++;
                        sum += j;
                    }

                    // Early stop if more than 4 divisors
                    if (count > 4) break;
                }
            }
        if(count==4) return sum;
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(auto x: nums){
            ans+=sumDivisors(x);
        }
        return ans;
    }
};