class Solution {
public:
    int maxTurbulenceSize(vector<int>& nums) {
        int n=nums.size();
        bool flip=false;
        int maxlen=1;
        int currlen=1;
        for(int i=1;i<n;i++){
            int curr=nums[i];
            int prev=nums[i-1];
            if(curr==prev){
                flip=false;
                currlen=1;
            }
            else if(prev<curr){
                if(!flip) currlen++;
                else currlen=2;
                flip=true;
            }
            else{
                if(flip) currlen++;
                else currlen=2;
                flip=false;
            }
            maxlen=max(currlen, maxlen);
        }
        return maxlen;
    }
};