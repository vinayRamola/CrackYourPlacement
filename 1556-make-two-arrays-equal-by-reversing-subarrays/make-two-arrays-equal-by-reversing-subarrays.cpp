class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        unordered_map<int,int> mp;

        for(auto &num:target){
            mp[num]++;
        }

        for(auto &num:arr){
            if(mp.find(num)==mp.end()) return false;
            else{
                mp[num]--;
            }
        }

        for(auto &it:mp){
            if(it.second != 0) return false;
        }
        return true;
    }
};
