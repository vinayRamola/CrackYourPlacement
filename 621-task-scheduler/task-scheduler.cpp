class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;

        int count=tasks.size();
        
        for(auto &ch:tasks){
            mp[ch]++;
        }

        int unique = mp.size();
        priority_queue<int> pq;

        for(auto &count:mp){
            pq.push(count.second);
        }

        int intervals = 0;

        while(!pq.empty()){
            int cycle = n+1;
            vector<int> temp;

            for(int i=0;i<cycle;i++){
                if(!pq.empty()){
                    temp.push_back(pq.top());
                    pq.pop();
                }
            }

            for(auto &ele:temp){
                if(--ele > 0){
                    pq.push(ele);
                }
            }

            intervals += !pq.empty() ? cycle:temp.size();
        }
     
        return intervals;
    }
};