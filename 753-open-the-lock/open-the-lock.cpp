class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited;
        unordered_set<string> dead;
        visited.insert("0000");
        for(auto x: deadends) dead.insert(x);
        if(dead.find("0000")!=dead.end()) return -1;
        if(dead.find(target)!=dead.end()) return -1;
        queue<string> q;
        q.push("0000");
        int turn =0;
        while(!q.empty()){
    int size = q.size();   // ✅ ADD THIS LINE

    for(int k = 0; k < size; k++){   // ✅ ADD THIS LOOP
        string top = q.front();
        q.pop();

        if(top == target) return turn;

        vector<string> tocheck;
        for(int i=0;i<4;i++){
            string temp=top;
            temp[i]=(temp[i]-'0'+9)%10+'0';
            tocheck.push_back(temp);
            temp=top;
            temp[i]=(temp[i]-'0'+1)%10+'0';
            tocheck.push_back(temp);
        }

        for(auto x: tocheck){
            if(dead.find(x)==dead.end() && visited.find(x)==visited.end()){
                q.push(x);
                visited.insert(x);
            }
        }
    }

    turn++;   // ✅ MOVED HERE (after processing level)
}
return -1;
    }
};