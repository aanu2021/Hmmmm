#include<bits/stdc++.h>
using namespace std;

bool static comp(const vector<int>& x, const vector<int>& y){
    if(x[1] == y[1]) return x[0] > y[0];
    return x[1] > y[1];
}

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize){
    
    int total = 0;
    int n = boxTypes.size();
    
    sort(boxTypes.begin(), boxTypes.end(), comp);
    
    for(int i=0;i<n && truckSize > 0;i++){
        if(truckSize >= boxTypes[i][0]){
            total += (boxTypes[i][0] * boxTypes[i][1]);
            truckSize -= boxTypes[i][0];
        }
        else{
            total += (truckSize * boxTypes[i][1]);
            truckSize = 0;
            break;
        }
    }
    
    return total;
    
}

int main(){
    
    int truckSize;
    
    int n;
    cin>>n;
    
    vector<vector<int>>boxTypes(n);
    
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        boxTypes[i] = {x,y};
    }
    
    cin>>truckSize;
    
    int answer = maximumUnits(boxTypes, truckSize);
    cout<<answer<<"\n";
    
    return 0;
    
}