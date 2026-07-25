class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        vector<pair<int, int>> myarr;
        int n=courses.size();
        for(int i=0;i<n;i++){
            myarr.push_back({courses[i][1], courses[i][0]});
        }
        sort(myarr.begin(), myarr.end());
        priority_queue<int> pq;
        int time=0;
        for(int i=0;i<n;i++){
            time+=myarr[i].second;
            pq.push(myarr[i].second); //push deadline
            if(time>myarr[i].first) {time-=pq.top(); pq.pop();}
        }
        return pq.size();
    }
};