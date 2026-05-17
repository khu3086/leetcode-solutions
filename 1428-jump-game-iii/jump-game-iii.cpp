class Solution {
public:
    void dfs(vector<int>& arr, vector<bool> visited, int curr, int n, bool& ans){
        if(curr<0||curr>n||visited[curr]) return;
        if(arr[curr]==0){
            visited[curr]=true;
            ans=true;
            return;
        }
        //can jump to arr[curr]+curr and arr[curr]-curr
        visited[curr]=true;
        dfs(arr, visited, curr+arr[curr], n, ans);
        dfs(arr, visited, curr-arr[curr], n, ans);
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool> vis(n, false);
        bool ans=false;
        dfs(arr, vis, start, n, ans);
        return ans;
    }
};