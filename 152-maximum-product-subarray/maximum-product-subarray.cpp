class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd=nums[0];
        int minProd=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int num=nums[i];
            if(num<0){
                swap(minProd, maxProd);
            }
            maxProd=max(maxProd*num, num);
            minProd=min(minProd*num, num);
            ans=max(maxProd, ans);
        }
        return ans;
    }
};