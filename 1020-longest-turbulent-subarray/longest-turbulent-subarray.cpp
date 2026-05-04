class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;

        int maxLen = 1;
        int currLen = 1;
        bool flip = false; // true means expecting opposite relation

        for(int i = 1; i < n; i++){
            int prev = nums[i-1];
            int curr = nums[i];

            if(curr == prev){
                currLen = 1;
                flip = false;
            }
            else if(curr > prev){
                if(!flip) currLen++;
                else currLen = 2;
                flip = true;
            }
            else { // curr < prev
                if(flip) currLen++;
                else currLen = 2;
                flip = false;
            }

            maxLen = max(maxLen, currLen);
        }

        return maxLen;
    }
};