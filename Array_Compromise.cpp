#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> nums = {1,6,7};
    int n = nums.size();

    vector<vector<int>> dp(20, vector<int>(n + 1, n));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 20; j++) {
            dp[j][i] = min(dp[j][i + 1], i) * ((nums[i] >> j) & 1) + (1 - ((nums[i] >> j) & 1)) * dp[j][i + 1];
        }
    }

    unordered_map<int, vector<vector<int>>> need;
    for (int i = 0; i < n; i++) {
        vector<int> x;
        for (int j = 0; j < 20; j++) {
            x.push_back(dp[j][i]);
        }
        sort(x.begin(), x.end(), greater<int>());
        int cur = 0;
        while (!x.empty() && x.back() != n) {
            cur |= nums[x.back()];
            need[cur].push_back({x.back(), x[x.size() - 2]});
            x.pop_back();
        }
    }

    for (auto &it : need) {
        reverse(it.second.begin(), it.second.end());
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        int j = nums[i];
        while (!need[j].empty() && need[j].back()[0] <= i) {
            res += max(need[j].back()[1] - i, 0);
            need[j].pop_back();
        }
    }

    cout << res << endl;

    return 0;
}
