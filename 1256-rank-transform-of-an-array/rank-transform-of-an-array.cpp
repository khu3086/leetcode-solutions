class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp=arr;
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        int rank=0;
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i])==mp.end()){
                mp[arr[i]]=++rank;
            }
        }
        for(int i=0;i<arr.size();i++){
            temp[i]=mp[temp[i]];
        }
        return temp;
    }
};