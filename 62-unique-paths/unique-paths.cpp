class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        int r = min(m - 1, n - 1);   // important

        for(int i = 0; i < r; i++){
            ans = ans * (m + n - 2 - r + 1 + i) / (i + 1);
        }
        return (int)ans;
    }
};