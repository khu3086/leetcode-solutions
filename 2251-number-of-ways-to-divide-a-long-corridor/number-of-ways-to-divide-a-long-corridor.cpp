class Solution {
public:
    int numberOfWays(string corridor) {
        int numSeat=0;
        int n=corridor.length();
        for(int i=0;i<n;i++){
            if(corridor[i]=='S') numSeat++;
        }
        if(numSeat==0||numSeat%2==1) return 0;
        vector<pair<int, int>> trackSeat;
        numSeat=0;
        int i=0;
        while(i<n){
            if(corridor[i]=='S'){
                int j=i+1;
                while (j < n && corridor[j] != 'S') j++;
                trackSeat.push_back({i, j});
                i=j+1;
            }
            else i++;
        }
        long long ans=1;
        long long mod=1000000007;
        int m=trackSeat.size();
        for(int i=0;i<m-1;i++){
            ans = (ans * (trackSeat[i + 1].first - trackSeat[i].second)) % mod;
        }
        return ans%mod;
    }
};