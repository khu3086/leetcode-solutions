class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd=nums[0];
        int minProd=nums[0];
        int res=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            int num=nums[i];
            if(num<0){
                swap(minProd, maxProd);
            }
            maxProd=max(maxProd*num, num);
            minProd=min(minProd*num, num);
            res=max(maxProd, res);
        }
        return res;
    }
};