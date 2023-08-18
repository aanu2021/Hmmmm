#include <bits/stdc++.h>
using namespace std;

long long solution(const vector<int>& indicator, const vector<int> profit, int k) {
    const int n = indicator.size();
    ++k;
    long long r = 0;
    for (int i = 0; k >> i; ++i) {
        if ((k >> i) & 1) {
            // In binary representation, the bitsize-or must have the prefix subset and the lowesst
            // the ith bit == 0
            k ^= 1 << i;
            long long may = 0;
            for (int j = 0; j < n; ++j) {
                if (((k >> i) | (indicator[j] >> i)) == (k >> i)) {
                    may += profit[j];
                }
            }
            r = max(may, r);
            k |= 1 << i;
        }
    }
    return r;
}

int main() {
    cout << solution({2, 3, 1, 5, 9}, {1, 2, 6, 1, 5}, 3) << endl;
    return 0;
}