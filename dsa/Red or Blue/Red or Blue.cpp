#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<long> miniCost(vector<int>& red, vector<int>& blue, int blueCost) {
    int n = red.size();

    vector<vector<int>> dp(n + 1, vector<int>(2));
    dp[0][0] = 0;
    dp[0][1] = blueCost;
    vector<long> ans(n + 1);

    for (int i = 1; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][0] + red[i - 1], dp[i - 1][1] + red[i - 1]);
        dp[i][1] = min(dp[i - 1][1] + blue[i - 1], dp[i - 1][0] + blue[i - 1] + blueCost);
        ans[i] = min(dp[i][1], dp[i][0]);
    }

    return ans;
}

int main()
{
    vector<int>red={40,20};
    vector<int>blue={30,25};
    int blueCost=5;
    
    vector<long>ans = miniCost(red,blue,blueCost);
    
    for(auto it:ans)cout<<it<<endl;

    return 0;
}