class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t res=0;
        for(int i=1;i<=32;i++){
            uint32_t lsb = n & 1;   // Extract the least significant bit
            res = (res << 1) | lsb; // Shift res left and add the extracted bit
            n >>= 1;
        }
        return res;
    }
};