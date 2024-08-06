class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> mp;
        for(auto &ch:word) mp[ch]++;

        vector<pair<int,int>> freq(mp.begin(),mp.end());

        sort(freq.begin(), freq.end(), [](const pair<int,int> &p1,const pair<int,int> &p2){
            return p1.second>p2.second;
        });

        int miniPushes = 0;
        int count=0;
        int temp=1;
        for(auto &ele:freq){
            if(count==8) temp++,count=0;
            miniPushes += ele.second*temp;
            count++;
        }
        return miniPushes;
    }   
};

//
// mapping -->  character count;

// char with max count sa starting allocating
// c -> 1
// w -> 1
// o -> 1
// k -> 1
// g -> 1
// n -> 1
// h -> 1
// a -> 1
// e -> 1
// t -> 1
