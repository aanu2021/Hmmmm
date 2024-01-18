#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int minSwaps(vector<int>& arr) {
    int len = arr.size();
    map<int, int> map;
    for (int i = 0; i < len; i++) {
        map[arr[i]] = i;
    }

    vector<int> nums = arr;
    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    vector<bool> visited(len, false);
    int ans = 0;
    for (int i = 0; i < len; i++) {
        if (visited[i] || map[nums[i]] == i)
            continue;

        int j = i, cycle_size = 0;
        while (!visited[j]) {
            visited[j] = true;
            j = map[nums[j]];
            cycle_size++;
        }

        if (cycle_size > 0) {
            ans += (cycle_size - 1);
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {3, 4, 1, 2};
    cout <<  minSwaps(arr) << endl;

    return 0;
}