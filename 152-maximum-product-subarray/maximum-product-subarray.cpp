class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=*max_element(nums.begin(), nums.end());
        int currmax=1;
        int currmin=1;
        for(auto n: nums){
            if(n==0){
                currmax=1; currmin=1;
            }
            else{
                int tmp=currmax*n;
                currmax=max({currmax*n, currmin*n, n});
                currmin=min({tmp, currmin*n, n});
                res=max(currmax, res);
            }
        }
        return res;
    }
};