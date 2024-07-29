class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int team=0;

        for(int j=0;j<n;j++){
            int leftSmaller=0,leftGreater=0,rightSmaller=0,rightGreater=0;

            for(int i=j-1;i>=0;i--){
                if(rating[i]<rating[j]) leftSmaller++;
                else if(rating[i]>rating[j]) leftGreater++;
            }

            for(int k=j+1;k<n;k++){
                if(rating[k]<rating[j]) rightSmaller++;
                else if(rating[k]>rating[j]) rightGreater++;
            }

            team += leftSmaller*rightGreater + leftGreater*rightSmaller;
        }
        return team;
    }
};