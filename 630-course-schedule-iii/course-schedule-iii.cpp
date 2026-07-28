class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<pair<int, int>> pq;
        int currDeadline=0;
        sort(courses.begin(), courses.end(),
     [](vector<int>& a, vector<int>& b) {
         return a[1] < b[1];
     });
        for(int i=0;i<courses.size();i++){
            currDeadline+=courses[i][0];
            pq.push({courses[i][0], courses[i][1]});
            if(!pq.empty()&&currDeadline>courses[i][1]){
                auto top=pq.top(); pq.pop();
                currDeadline-=top.first;
            }
        }
        return pq.size();
    }
};