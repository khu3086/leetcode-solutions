class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead;
        for(auto d: deadends) dead.insert(d);
        if(dead.find("0000")!=dead.end()) return -1;
        if(dead.find(target)!=dead.end()) return -1;
        unordered_set<string> visited;
        visited.insert("0000");
        queue<string> q;
        q.push("0000");
        int curr=0;
        if(target=="0000") return curr;
        while(!q.empty()){
            int k=q.size();
            for(int i=0;i<k;i++){
                string top=q.front();
                q.pop();

                string temp=top;
                temp[0]=(temp[0]-'0'+1)%10+'0';
                if(temp==target) return curr+1;
                if(dead.find(temp)==dead.end()&&visited.find(temp)==visited.end()){
                    q.push(temp);
                    visited.insert(temp);
                }
                temp=top;
                temp[0]=(temp[0]-'0'+9)%10+'0';
                if(temp==target) return curr+1;
                if(dead.find(temp)==dead.end()&&visited.find(temp)==visited.end()){
                    q.push(temp);
                    visited.insert(temp);
                }
                temp=top;
                temp[1]=(temp[1]-'0'+9)%10+'0';
                if(temp==target) return curr+1;
                if(dead.find(temp)==dead.end()&&visited.find(temp)==visited.end()){
                    q.push(temp);
                    visited.insert(temp);
                }
                temp=top;
                temp[1]=(temp[1]-'0'+1)%10+'0';
                if(temp==target) return curr+1;
                if(dead.find(temp)==dead.end()&&visited.find(temp)==visited.end()){
                    q.push(temp);
                    visited.insert(temp);
                }
                temp=top;
                temp[2]=(temp[2]-'0'+9)%10+'0';
                if(temp==target) return curr+1;
                if(dead.find(temp)==dead.end()&&visited.find(temp)==visited.end()){
                    q.push(temp);
                    visited.insert(temp);
                }
                temp=top;
                temp[2]=(temp[2]-'0'+1)%10+'0';
                if(temp==target) return curr+1;
                if(dead.find(temp)==dead.end()&&visited.find(temp)==visited.end()){
                    q.push(temp);
                    visited.insert(temp);
                }
                temp=top;
                temp[3]=(temp[3]-'0'+9)%10+'0';
                if(temp==target) return curr+1;
                if(dead.find(temp)==dead.end()&&visited.find(temp)==visited.end()){
                    q.push(temp);
                    visited.insert(temp);
                }
                temp=top;
                temp[3]=(temp[3]-'0'+1)%10+'0';
                if(temp==target) return curr+1;
                if(dead.find(temp)==dead.end()&&visited.find(temp)==visited.end()){
                    q.push(temp);
                    visited.insert(temp);
                }
            }
            curr++;
        }
        return -1;
    }
};