class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> myset;
        for(auto x: deadends) myset.insert(x);
        if(myset.find("0000")!=myset.end()) return -1;
        unordered_set<string> visited;
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        visited.insert("0000");
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int moves=top.second;
            string num=top.first;
            string temp=num;
            if(num==target) return moves;
            //num[0]+1
            int repl=(num[0]-'0'+1)%10+'0';
            temp[0]=repl;
            if(visited.find(temp)==visited.end()&&myset.find(temp)==myset.end()){
                visited.insert(temp);
                q.push({temp, moves+1});
            }
            //num[0]-1
             repl=(num[0]-'0'+9)%10+'0';
            temp[0]=repl;
            if(visited.find(temp)==visited.end()&&myset.find(temp)==myset.end()){
                visited.insert(temp);
                q.push({temp, moves+1});
            }
            temp=num;
            //num[1]+1
             repl=(num[1]-'0'+1)%10+'0';
            temp[1]=repl;
            if(visited.find(temp)==visited.end()&&myset.find(temp)==myset.end()){
                visited.insert(temp);
                q.push({temp, moves+1});
            }
            //num[1]-1
             repl=(num[1]-'0'+9)%10+'0';
            temp[1]=repl;
            if(visited.find(temp)==visited.end()&&myset.find(temp)==myset.end()){
                visited.insert(temp);
                q.push({temp, moves+1});
            }
            temp=num;
            //num[2]+1
             repl=(num[2]-'0'+1)%10+'0';
            temp[2]=repl;
            if(visited.find(temp)==visited.end()&&myset.find(temp)==myset.end()){
                visited.insert(temp);
                q.push({temp, moves+1});
            }
            //num[2]-1
             repl=(num[2]-'0'+9)%10+'0';
            temp[2]=repl;
            if(visited.find(temp)==visited.end()&&myset.find(temp)==myset.end()){
                visited.insert(temp);
                q.push({temp, moves+1});
            }
            temp=num;
            //num[3]+1
             repl=(num[3]-'0'+1)%10+'0';
            temp[3]=repl;
            if(visited.find(temp)==visited.end()&&myset.find(temp)==myset.end()){
                visited.insert(temp);
                q.push({temp, moves+1});
            }
            //num[3]-1
             repl=(num[3]-'0'+9)%10+'0';
            temp[3]=repl;
            if(visited.find(temp)==visited.end()&&myset.find(temp)==myset.end()){
                visited.insert(temp);
                q.push({temp, moves+1});
            }

        }
        return -1;
    }
};