class Solution {
public:
    int bestClosingTime(string customers) {
        int yes=0;
        int no=0;
        int minPenalty=INT_MAX;
        int n=customers.size();
        int hr=0;
        for(int i=0;i<n;i++){
            if(customers[i]=='Y') yes++;
            else no++;
        }
        if(yes==0) return 0;
        int penalty=yes; //0th hr penalty
        for(int i=0;i<n;i++){
            minPenalty=min(penalty, minPenalty);
            if(customers[i]=='Y')
            penalty-=1;
            else penalty+=1;
            if(penalty>=0&&penalty<minPenalty) hr=i+1;
        }
        return hr;
    }
};