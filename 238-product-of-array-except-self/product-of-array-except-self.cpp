class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        bool zero=false;
        bool twozero=false;
        int mult=1;
        for(auto num: nums){
            if(zero&&num==0){
                twozero=true;
                continue;
            }
            if(num==0){
                zero=true;
                continue;
            }
            mult*=num;
        }
        vector<int> ans;
        for(auto num: nums){
            if(twozero){
                ans.push_back(0); continue;
            }
            if(zero){
                if (num == 0) ans.push_back(mult);  // ✅ key fix
                else ans.push_back(0);              // ✅ key fix
                continue;
            }
            ans.push_back(mult/num);
        }
        return ans;

    }
};