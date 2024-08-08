class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> countBit(n+1,0);
        countBit[0]=0;
        for(int i=1;i<=n;i++){
            if(i%2==1) countBit[i] = countBit[i/2]+1;
            else countBit[i] = countBit[i/2];
        }   
        return countBit;
    }
};