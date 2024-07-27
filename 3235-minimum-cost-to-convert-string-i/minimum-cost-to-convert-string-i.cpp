class Solution {
public:
    void floydWarshall(vector<vector<long long>> &adjMat,vector<char>& original, vector<char>& changed, vector<int>& cost){
        for(int i=0;i<original.size();i++){
            int s = original[i]-'a';
            int t = changed[i]-'a';

            adjMat[s][t] = min(adjMat[s][t],(long long)cost[i]);
        }

        // apply floydwarshall
        for(int k=0;k<26;++k){
            for(int i=0;i<26;++i){
                for(int j=0;j<26;++j){
                    adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> adjMat(26, vector<long long> (26,INT_MAX));

        floydWarshall(adjMat,original,changed,cost); // update adjMat with shortest path

        long long ans = 0;

        for(int i=0;i<source.length();i++){
            if(source[i] == target[i]){
                continue;
            }

            if(adjMat[source[i]-'a'][target[i]-'a'] == INT_MAX){
                return -1;
            }
            
            ans  += adjMat[source[i]-'a'][target[i]-'a'];
        }
        return ans;   
    }
};