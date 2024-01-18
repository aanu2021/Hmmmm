#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int countSwaps(vector<int>& arrA, vector<int>& arrB) {
    unordered_map<int, int> mpp1, mpp2;
    for (auto it : arrA) mpp1[it]++;
    for (auto it : arrB) mpp2[it]++;
    vector<int> diff;
    for (auto it : mpp1) {
        if (mpp2.find(it.first) != mpp2.end()) {
            if ((it.second + mpp2[it.first]) & 1) {
                return -1;
            }
            int t = (abs(it.second - mpp2[it.first])) / 2;
            while (t--) {
                diff.push_back(it.first);
            }
        } else {
            if ((it.second) & 1) {
                return -1;
            }
            int t = (it.second) / 2;
            while (t--) {
                diff.push_back(it.first);
            }
        }
    }
    for (auto it : mpp2) {
        if (mpp1.find(it.first) == mpp1.end()) {
            if ((it.second) & 1) {
                return -1;
            }
            int t = (it.second) / 2;
            while (t--) {
                diff.push_back(it.first);
            }
        }
    }
    sort(diff.begin(), diff.end());
    int diffsize = diff.size() / 2;
    int ans = 0;
    for (int i = 0; i < diffsize; i++) {
        ans += diff[i];
    }
    return ans;
}

int main() {
    vector<int> arrA = {4, 2, 2, 2};
    vector<int> arrB = {1, 4, 1, 2};

    cout << countSwaps(arrA, arrB) << endl;

    return 0;
}