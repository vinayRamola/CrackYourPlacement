class Solution {
public:
    int hammingWeight(int n) {
        int bits=0;
        // while(n){
        //     int mul = n&1;
        //     if(mul){
        //         bits++;
        //     }
        //     n=n>>1;
        // }

        // second approach
        while(n){
            n=n&(n-1);
            bits++;
        }
        return bits;
    }
};

// important

// ake right most bit 0
// n&(n-1)
// 1101 -> 13
// 1100 -> 12
// 1100


// 1 0 1 1