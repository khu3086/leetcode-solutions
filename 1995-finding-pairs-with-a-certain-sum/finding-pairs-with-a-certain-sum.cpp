class FindSumPairs {
public:
    unordered_map<int, int> freq;
    vector<int> num1, num2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        num1=nums1;
        num2=nums2;
        for(int i=0;i<nums2.size();i++) freq[num2[i]]++;
    }
    
    void add(int index, int val) {
        freq[num2[index]]--;
        num2[index]+=val;
        freq[num2[index]]++;
    }
    
    int count(int tot) {
        int ans=0;
        for(int i=0;i<num1.size();i++){
            ans+=freq[tot-num1[i]];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */