class Solution {
public:
    int hammingWeight(int n) {
        int a=1;
        int bits=0;
        while(n){
            int mul = n&a;
            if(mul){
                bits++;
            }
            n=n>>1;
        }
        return bits;
    }
};
// 1 0 1 1