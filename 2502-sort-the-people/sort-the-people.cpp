class Solution {
public:
    bool static comp(pair<int,string> p1,pair<int,string> p2){
        return p1.first>p2.first;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> v;

        for(int i=0;i<names.size();i++){
            v.push_back({heights[i],names[i]});
        }

        sort(v.begin(),v.end(),comp);

        vector<string> ans;

        for(auto it:v){
            ans.push_back(it.second);
        }

        return ans;
    }
};