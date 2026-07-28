class MyCalendar {
public:
    vector<pair<int, int>> st;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        if(st.empty()){
            st.push_back({startTime, endTime});
            return true;
        }
        int low=0;
        int high=st.size()-1;
        int ans=-1;
        while(low<=high){
            int middle=low+(high-low)/2;
            int mid=st[middle].second;
            if(mid<=startTime){
                ans=middle;
                low=middle+1;
            }
            else{
                high=middle-1;
            }
        } // find greatest end time just smaller than new startime
        if(ans==-1){
            //no endtime just lower than startime
            //check first
            if(endTime>st[0].first) return false;
            st.insert(st.begin(), {startTime, endTime});
            return true;
        }
        else{
            //ans is just before insertion, need to check overlap with next ele
            if(ans+1>=st.size()){
                st.push_back({startTime, endTime});
                return true;
            }
            if(endTime>st[ans+1].first) return false;
            st.insert(st.begin()+ans+1, {startTime, endTime});
            return true;
        }

    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */