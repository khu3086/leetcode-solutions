class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> seta;
        unordered_set<int> setb;
        int count=0;
        vector<int> ans;
        for(int i=0;i<A.size();i++){
            seta.insert(A[i]);
            setb.insert(B[i]);
            if(seta.find(B[i])!=seta.end()) count++;
            if(setb.find(A[i])!=setb.end()&&A[i]!=B[i]) count++;
            ans.push_back(count);
        }
        return ans;
    }
};