class Solution {
public:
    void solve(int n,int open,int close,vector<string> &v,string temp){
        if(temp.size()==2*n){
            v.push_back(temp);
            return;
        }
        if (open < n) {
            solve(n, open + 1, close, v, temp + '(');
        }
        
        if (close < open) {
            solve(n, open, close + 1, v, temp + ')');
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string> v;
        solve(n,0,0,v,"");
        return v;
    }
};