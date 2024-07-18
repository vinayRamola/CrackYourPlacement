#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int preSum = 0;
        unordered_map<int, int> remainderCount;
        remainderCount[0] = 1; // To handle the case where the subarray itself is divisible by k

        for (int i = 0; i < n; i++) {
            preSum += nums[i];
            int remainder = preSum % k;

            // To handle negative remainders, adjust to be in the range [0, k-1]
            if (remainder < 0) {
                remainder += k;
            }

            if (remainderCount.find(remainder) != remainderCount.end()) {
                count += remainderCount[remainder];
            }

            remainderCount[remainder]++;
        }

        return count;
    }
};
