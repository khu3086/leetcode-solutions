class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead;
        queue<string> q;
        for(auto d: deadends) dead.insert(d);

        if(dead.find("0000")!=dead.end()) return -1;

        q.push("0000");
        unordered_set<string> visited;
        visited.insert("0000");

        int curr = 0;

        while(!q.empty()){
            int k = q.size();

            for(int i = 0; i < k; i++) {
                string top = q.front();
                q.pop();

                if(top == target) return curr;

                string temp = top;

                temp = top;
                temp[0]=(temp[0]-'0'+1)%10+'0';
                if(dead.find(temp)==dead.end() && !visited.count(temp)) {
                    q.push(temp);
                    visited.insert(temp);
                }

                temp = top;
                temp[0]=(temp[0]-'0'+9)%10+'0';
                if(dead.find(temp)==dead.end() && !visited.count(temp)) {
                    q.push(temp);
                    visited.insert(temp);
                }

                temp = top;
                temp[1]=(temp[1]-'0'+1)%10+'0';
                if(dead.find(temp)==dead.end() && !visited.count(temp)) {
                    q.push(temp);
                    visited.insert(temp);
                }

                temp = top;
                temp[1]=(temp[1]-'0'+9)%10+'0';
                if(dead.find(temp)==dead.end() && !visited.count(temp)) {
                    q.push(temp);
                    visited.insert(temp);
                }

                temp = top;
                temp[2]=(temp[2]-'0'+1)%10+'0';
                if(dead.find(temp)==dead.end() && !visited.count(temp)) {
                    q.push(temp);
                    visited.insert(temp);
                }

                temp = top;
                temp[2]=(temp[2]-'0'+9)%10+'0';
                if(dead.find(temp)==dead.end() && !visited.count(temp)) {
                    q.push(temp);
                    visited.insert(temp);
                }

                temp = top;
                temp[3]=(temp[3]-'0'+1)%10+'0';
                if(dead.find(temp)==dead.end() && !visited.count(temp)) {
                    q.push(temp);
                    visited.insert(temp);
                }

                temp = top;
                temp[3]=(temp[3]-'0'+9)%10+'0';
                if(dead.find(temp)==dead.end() && !visited.count(temp)) {
                    q.push(temp);
                    visited.insert(temp);
                }
            }

            curr++; // ✅ moved outside for-loop
        }

        return -1; // ✅ correct final return
    }
};