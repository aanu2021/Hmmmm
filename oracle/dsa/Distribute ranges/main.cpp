#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& ranges){
    int m = ranges.size();
    sort(ranges.begin(),ranges.end());
    int n = 0;
    int prev_end = INT_MIN;
    for(int i=0;i<m;i++){
        if(ranges[i][0]>prev_end){
            n++;
            prev_end = ranges[i][1];
        }else{
            prev_end = max(prev_end,ranges[i][1]);
        }
    }
    
    int ways = 1;
    const int mod = 1e9+7;
    for(int i=1;i<=n;i++){
        ways = (ways*2)%mod;
    }
    return ways-2;
}

int main()
{
    // cout<<"Hello World";
    vector<vector<int>>ranges{{1,5},{3,8},{10,15},{13,14},{20,100}};
    cout<<solve(ranges);
    return 0;
}