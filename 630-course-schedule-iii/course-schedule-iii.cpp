class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        for(auto& x: courses){
            reverse(x.begin(), x.end());
        }
        sort(courses.begin(), courses.end());
        priority_queue<pair<int, int>> pq;
        int currTime=0;
        for(int i=0;i<courses.size();i++){
            currTime+=courses[i][1];
            pq.push({courses[i][1], courses[i][0]});
            if(currTime>courses[i][0]){
                auto top=pq.top(); pq.pop();
                currTime-=top.first;
            }
        }
        return pq.size();
    }
};