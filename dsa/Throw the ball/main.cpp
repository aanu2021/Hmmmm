#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int help(vector<int>nums , int x){
    unordered_map<int , int>m;
    for(int i=0 ; i<nums.size() ; i++){
        m[i+1]=nums[i];
    }
    int curr=1;
    while(x--) curr=m[curr];
    
    return curr;
}

int main(){
    vector<int>reciver={6, 5, 2, 5, 3, 2};
    int seconds=7;
    int ans=help(reciver, seconds);
    cout<<ans<<endl;
}