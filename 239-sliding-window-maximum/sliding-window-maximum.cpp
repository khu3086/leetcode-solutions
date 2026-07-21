class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //number of windows here is = len-k+1
        //to check where we are
        vector<int> ans;
        priority_queue<pair<int, int>> pq; //maxheap
        int left=0;
        int n=nums.size();
        for(int left=0;left<n;left++){
            if(left==0){
                for(int right=0;right<k;right++){
                    pq.push({nums[right], right});
                }
                ans.push_back(pq.top().first);
            }
            else{
                if (left + k - 1 < n)
                    pq.push({nums[left + k - 1], left + k - 1});

                while (!pq.empty() && pq.top().second < left)
                    pq.pop();

                if (left + k - 1 < n)
                    ans.push_back(pq.top().first);
            }
        }
        return ans;
    }
};