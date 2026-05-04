class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        bool flip=false;
        int n=arr.size();
        int currlen=1;
        int maxlen=1;
        for(int i=1;i<n;i++){
            int curr=arr[i];
            int prev=arr[i-1];
            if(curr==prev){
                currlen=1;
                flip=false;
            }
            else if(curr<prev){
                if(flip) currlen++;
                else currlen=2;
                flip=false;
            }
            else{
                if(!flip) currlen++;
                else currlen=2;
                flip=true;
            }
            maxlen=max(maxlen, currlen);
        }
        return maxlen;
    }
};