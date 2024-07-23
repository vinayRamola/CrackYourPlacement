class Solution {
public:
    static bool comp(pair<int,int> p1,pair<int,int> p2){
        if(p1.second<p2.second) return true;
        else if(p1.second==p2.second) return p1.first>p2.first;
        else return false;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(auto num:nums){
            mp[num]++;
        }
        vector<pair<int,int>> v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),comp);

        vector<int> ans;

        for(auto ele:v){
            while(ele.second--)
                ans.push_back(ele.first);
        }
        return ans;
    }
};