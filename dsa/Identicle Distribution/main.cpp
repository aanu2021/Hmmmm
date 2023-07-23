#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& cards) {
    int maxNum = *max_element(cards.begin(), cards.end());
    if(maxNum==1)maxNum=2;
    int minChanges = INT_MAX;

    for (int i = 2; i <= maxNum; i++) {
        int changes = 0;
        for (int num : cards) {
            int rem = num % i;
            changes += (rem == 0) ? 0 : (i - rem);
        }
        minChanges = min(minChanges, changes);
    }

    return minChanges;
}

int main(){
    vector<int>arr{3, 8, 7, 6, 4};
    cout<<solve(arr);
    return 0;
}