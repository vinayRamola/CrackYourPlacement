class Solution {
public:
    bool isPali(const string &s, int left, int right, bool flag) {
        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                if (flag) return false;
                return isPali(s, left + 1, right, true) || isPali(s, left, right - 1, true);
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        return isPali(s, 0, s.length() - 1, false);
    }
};
