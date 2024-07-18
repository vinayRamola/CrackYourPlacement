#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        if (n < 3) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int i = 0;  // Initialize i properly

        while (i < n - 2) { 
            if (i > 0 && nums[i] == nums[i - 1]) {  // Skip duplicate elements for i
                ++i;
                continue;
            }

            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    // Skip duplicate elements for j and k
                    while (j < k && nums[j] == nums[j + 1]) ++j;
                    while (j < k && nums[k] == nums[k - 1]) --k;
                    ++j;
                    --k;
                } else if (sum < 0) {
                    ++j;
                } else {
                    --k;
                }
            }
            ++i;  
        }

        return ans;
    }
};
