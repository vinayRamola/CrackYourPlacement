class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int len = s.length();
        
        int id = -1;
        for (int i = len - 1; i > 0; i--) {
            if (s[i] > s[i - 1]) {
                id = i - 1;
                break;
            }
        }

        if (id == -1) {
            return -1;
        }

        for (int i = len - 1; i > id; i--) {
            if (s[i] > s[id]) {
                swap(s[i], s[id]);
                break;
            }
        }

        sort(s.begin() + id + 1, s.end());

        long long m = stoll(s);

        return (m > INT_MAX || m <= n) ? -1 : m;
    }
};