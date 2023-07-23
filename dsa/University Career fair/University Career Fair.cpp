#include<bits/stdc++.h>
using namespace std;

int maxEvents(vector<int>&arr,vector<int>&dur,int n){
    vector<vector<int>>intervals;
    for(int i=0;i<n;i++){
        int dep=arr[i]+dur[i];
        intervals.push_back({arr[i],dep});
    }
    sort(intervals.begin(),intervals.end());
    int e=intervals[0][1],ans=1,j=0;
    for(int i=1;i<n;i++){
        if(intervals[i][0]>=e){
            ans++;
            e=intervals[i][1];
        }
        else{
            e=min(e,intervals[i][1]);
        }
    }
    return ans;
}

int main(){
    int n = 5;
    vector<int>arr={1, 3, 3, 5, 7};
    vector<int>dur={2, 2, 1, 2, 1};
    
    cout<<maxEvents(arr,dur,n)<<endl;
}