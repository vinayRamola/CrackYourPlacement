class Solution {
public:
    int change(int num, unordered_map<int, int>& mp) {
        int temp = 0;
        int factor = 1;
        if (num == 0) { // Handle the case where num is 0
        return mp[0];
    }
        while (num > 0) {
            int lastDigit = num % 10;
            num /= 10;
            temp += mp[lastDigit] * factor;
            factor *= 10;
        }
        return temp;
    }

    static bool comp(pair<pair<int, int>, int> p1,
                     pair<pair<int, int>, int> p2) {
        if (p1.first.first < p2.first.first)
            return true;
        else if (p1.first.first == p2.first.first) {
            return p1.second < p2.second;
        } else
            return false;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = mapping.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[i] = mapping[i];
        }
        vector<pair<pair<int, int>, int>> v; // {{newValue,oldVaue},intdex}
        for (int i = 0; i < nums.size(); i++) {
            int temp = change(nums[i], mp);
            v.push_back({{temp, nums[i]}, i});
        }

        sort(v.begin(), v.end(), comp);

        vector<int> ans;
        for (auto& ele : v) {
            ans.push_back(ele.first.second);
        }

        return ans;
    }
};
// 991 338 38

// {669,1} {007,2} {07,3}

// mapping

// chnage the digits of nums and push in v

//{{9,0},0}{}
