class Solution {
public:
    bool static comp(const pair<int,int> &p1,const pair<int,int> &p2){
        return p1.second>p2.second;
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int,int>> temp;

        for(int i=0;i<n;i++){
            temp.push_back({plantTime[i],growTime[i]});
        }

        sort(temp.begin(),temp.end(),comp);

        int time=0;
        int maxGrowTime=0;
        for(auto &plant:temp){
            time+=plant.first;
            maxGrowTime = max(maxGrowTime,time+plant.second);
        }

        return maxGrowTime;
    }
};