class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int ans = 0;

        vector<int> prefix(n , 0);

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                prefix[i] = 1;
            }
        }

        for (int i = 1; i < n; i++) {
            prefix[i] += prefix[i - 1];
        }

        for (int i = 0; i < n; i++) {
            int zeros = 0, ones = 0;
            for (int j = i; j < n; j++) {
                ones = prefix[j];
                if (i != 0)
                    ones -= prefix[i - 1];
                zeros = (j - i + 1) - ones;

                if (zeros * zeros > ones)
                    j += ((zeros * zeros) - ones - 1); // next possible

                if ((zeros * zeros) <= ones) {
                    ans++;

                    // check for another string starting from i
                    if (zeros * zeros < ones) {
                        int diff = sqrt(ones) - (zeros);
                        int nextj = j + diff;
                        if (nextj >= n) {
                            ans += (n - j - 1);
                        } else {
                            ans += diff;
                        }
                        j = nextj;
                    }
                }
            }
        }
        return ans;
    }
};