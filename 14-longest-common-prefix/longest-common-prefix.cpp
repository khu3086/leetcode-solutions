class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int minL=999;
        for(auto s: strs){
            minL=s.length()<minL?s.length():minL;
        }
        int count=0;
        for(int i=0;i<minL;i++){
            int flag=1;
            for(int j=0;j<n-1;j++){
                if(strs[j][i]!=strs[j+1][i]) flag=0;
            }
            if(flag==0) break;
            count++;
        }
        cout<<count;
        return strs[0].substr(0, count);
    }
};