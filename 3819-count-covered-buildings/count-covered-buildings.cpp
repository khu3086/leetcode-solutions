class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, pair<int, int>> row;
        unordered_map<int, pair<int, int>> col;
        for(auto x: buildings){
            if(row.find(x[0])==row.end()){
                row[x[0]].first=x[1];
                row[x[0]].second=x[1];
            }
            else{
                row[x[0]].first=max(x[1], row[x[0]].first);
                row[x[0]].second=min(x[1], row[x[0]].second);
            }

            if(col.find(x[1])==col.end()){
                col[x[1]].first=x[0];
                col[x[1]].second=x[0];
            }
            else{
                col[x[1]].first=max(x[0], col[x[1]].first);
                col[x[1]].second=min(x[0], col[x[1]].second);
            }
        }
        int count=0;
        for(auto x: buildings){
            bool rowcheck=false;
            bool colcheck=false;
            if(x[1] < row[x[0]].first && x[1] > row[x[0]].second) rowcheck=true;
            if(x[0] < col[x[1]].first && x[0] > col[x[1]].second) colcheck=true;
            if(rowcheck && colcheck) count++;
        }
        return count;
    }
};