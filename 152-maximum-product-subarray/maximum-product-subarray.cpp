class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currmin=nums[0]; int currmax=nums[0];
        int res=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            int x=nums[i];
            if(x<0){
                swap(currmax, currmin);
            }
            currmax=max(currmax*x, x);
            currmin=min(currmin*x, x);
            res=max(currmax, res);
        }
        return res;
    }
};