class Solution {
public:
    unordered_set<string> st;
    int dp[301] ;
    bool solve(string s, vector<string>& wordDict,int idx){
        if(idx>=s.length()){
            return true;
        }

        if(dp[idx]!=-1) return dp[idx];

        if(st.find(s) != st.end()) return true;

        for(int l=1;l<=s.length();l++){
            string temp = s.substr(idx,l);
            if(st.find(temp) != st.end() and solve(s,wordDict,idx+l)) return dp[idx] = true;   
        }

        return dp[idx]= false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        memset(dp,-1,sizeof(dp));

        for(string &word:wordDict){
            st.insert(word);
        }
        return solve(s,wordDict,0);
    }
};