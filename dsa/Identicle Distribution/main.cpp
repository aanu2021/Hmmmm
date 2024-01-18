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



** Another Code


#include<bits/stdc++.h>
using namespace std;
int solve(vector&nums){
int ans=1e9;
int n=nums.size();
for(int i=2;i<=500;i++){
    int res=0;
    for(auto x: nums){
        res+=(x%i);
    }
    ans=min(ans,res);
}
return ans;
}
int main(){
int n;
cin>>n;
vector arr(n);
for(int i=0;i<n;i++){
cin>>arr[i];
}
cout<<solve(arr)<<endl;
}
