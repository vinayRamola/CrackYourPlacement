class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length();
        int m = haystack.length();
        if(haystack==needle) return 0;

        for(int i=0;i<=m-n;i++){
            string subst = haystack.substr(i,n);
            if(subst==needle) return i;
        }

        return -1;
    }
}; 