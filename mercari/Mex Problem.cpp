#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& A, int x){
    int n = A.size();
    unordered_map<int,int>freq;
    for(int i=0;i<n;i++){
        freq[A[i]%x]++;
    }
    for(int i=0;i<n;i++){
        if(freq[i%x] > 0){
            freq[i%x]--;
        }
        else{
            return i;
        }
    }
    return n;
}

int main(){
    
    int n;
    cin>>n;
    
    vector<int>A(n);
    for(int i=0;i<n;i++) cin>>A[i];
    
    int x;
    cin>>x;
    
    int answer = solve(A,x);
    cout<<answer<<"\n";
    
    
    return 0;
    
}