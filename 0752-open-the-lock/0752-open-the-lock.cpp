class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
    unordered_set<string> deadendSet(deadends.begin(),deadends.end());
    if(deadendSet.count("0000")){
        return -1;
    }
    queue<string>q;
    q.push("0000");
    unordered_set<string> visited;
    visited.insert("0000");
    
    int steps=0;

    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;++i)
        {
            string curr=q.front();
            q.pop();

            if(curr==target)
            {
                return steps;
            }
            for(int j=0;j<4;++j)
            {
                char c=curr[j];
                curr[j]=(c=='9') ? '0':c+1;
                if(!deadendSet.count(curr) && !visited.count(curr)){
                visited.insert(curr);
                q.push(curr);
                }
                curr[j] = (c == '0') ? '9' : c - 1;
                    if (!deadendSet.count(curr) && !visited.count(curr)) {
                        visited.insert(curr);
                        q.push(curr);
                    }
                    curr[j] = c;
            }
        }
    steps++;
    }
return -1;
    }
};