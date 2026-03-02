class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Count trailing zeros for each row
        vector<int> zeroes(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--) {
                zeroes[i]++;
            }
        }
        
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            int need = n - 1 - i; // trailing zeros needed for row i
            
            // Find the nearest row >= i that satisfies the requirement
            int found = -1;
            for (int k = i; k < n; k++) {
                if (zeroes[k] >= need) {
                    found = k;
                    break;
                }
            }
            
            if (found == -1) return -1; // No valid row exists
            
            // Bubble that row up to position i (swap adjacent rows)
            while (found > i) {
                swap(zeroes[found], zeroes[found - 1]);
                found--;
                swaps++;
            }
        }
        
        return swaps;
    }
};