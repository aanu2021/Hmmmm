#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int getStartPoint(vector<int>& magic, vector<int>& dist) {
    int s = 0, r = 0, d = 0;
    for (int i = 0; i < magic.size(); i++) {
        r += magic[i] - dist[i];
        if (r < 0) {
            s = i + 1;
            d += r;
            r = 0;
        }
    }
    return (d + r >= 0) ? s : -1;
}

int main() {
    vector<int> magic = {2, 4, 5, 2};
    vector<int> dist = {4, 3, 1, 3};
    cout << getStartPoint(magic, dist) << endl;

    return 0;
}






