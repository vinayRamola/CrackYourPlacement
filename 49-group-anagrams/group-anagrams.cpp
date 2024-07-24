#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;

        unordered_map<string, vector<string>> anagramGroups;

        for (int i = 0; i < n; i++) {
            string sortedStr = strs[i];
            sort(sortedStr.begin(), sortedStr.end());
            anagramGroups[sortedStr].push_back(strs[i]);
        }

        for (const auto& entry : anagramGroups) {
            ans.push_back(entry.second);
        }

        return ans;
    }
};
