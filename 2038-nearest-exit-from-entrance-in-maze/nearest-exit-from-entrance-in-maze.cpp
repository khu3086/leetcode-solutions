class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int count=0;
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        vector<vector<int>> dir={{0,1}, {0, -1}, {1, 0}, {-1, 0}};
        int m=maze.size();
        int n=maze[0].size();
        maze[entrance[0]][ entrance[1]]='#';
        //vis->#
        while (!q.empty()) {
    int sz = q.size();

    while (sz--) {
        auto [i, j] = q.front();
        q.pop();

        if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) &&
            !(i == entrance[0] && j == entrance[1]))
            return count;

        for (auto &d : dir) {
            int x = i + d[0];
            int y = j + d[1];

            if (x >= 0 && y >= 0 && x < m && y < n &&
                maze[x][y] == '.') {
                maze[x][y] = '#';
                q.push({x, y});
            }
        }
    }

    count++;
}
        return -1;
    }
};