class Solution {
public:
    // Static comparator function for min-heap based on the second element
    static bool comp(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second; // Min-heap (inverted to get max-heap behavior)
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        // Count frequency of each number
        for (const auto &num : nums) {
            mp[num]++;
        }

        // Priority queue with static member function as comparator
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&comp)> pq(&comp);

        // Insert elements into the priority queue
        for (const auto &it : mp) {
            pq.push({it.first, it.second});
        }

        // Extract the top k elements
        vector<int> ans;
        while (k-- && !pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        return ans;
    }
};