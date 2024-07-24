class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<string, pair<int, int>>> v;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            string mp;
            int x = num;
            if (num == 0) {
                mp += to_string(mapping[0]);
            }
            while (x > 0) {
                int m = x % 10;
                mp += to_string(mapping[m]);
                x /= 10;
            }
            reverse(mp.begin(), mp.end());
            v.push_back(make_pair(mp, make_pair(num, i)));
        }
        sort(v.begin(), v.end(), [&](auto a, auto b) {
            int x = stoi(a.first);
            int y = stoi(b.first);

            if (x < y) {
                return true;
            } else if (x == y) {
                return a.second.second < b.second.second;
            } else {
                return false;
            }
        });
        for (int i = 0; i < v.size(); i++) {
            nums[i] = v[i].second.first;
        }
        return nums;
    }
};
