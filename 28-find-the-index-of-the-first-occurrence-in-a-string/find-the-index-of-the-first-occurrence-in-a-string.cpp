class Solution {
public:
    int strStr(string haystack, string needle) {
         int n = needle.length();
        int m = haystack.length();
        
        if (needle.empty()) return 0; // If needle is empty, return 0
        if (m < n) return -1; // If haystack is shorter than needle, return -1

        for (int i = 0; i <= m - n; ++i) {
            if (haystack.substr(i, n) == needle) {
                return i;
            }
        }

        return -1;
    }
}; 