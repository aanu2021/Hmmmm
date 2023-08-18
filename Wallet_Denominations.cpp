#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
 
     int t=1;
    //  cin>>t;
     
     while(t--){
         
        ll n;
        cin>>n;
        
        vector<ll>a(n);
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        
        ll MAX = *max_element(a.begin(),a.end());
        vector<ll>freq(MAX + 1,0LL);
        
        for(ll i=0;i<n;i++){
            freq[a[i]]++;
        }
        
        vector<ll>occ(MAX+1,0LL);
        
        for(ll i=1;i<=MAX;i++){
            occ[i] = freq[i];
            occ[i] += occ[i-1];
        }
        
        ll minOps = 1e18;
        
        for(ll i=1;i<=MAX;i++){
            ll ele = i;
            ll currOps = 0LL;
            ll cnt = 1LL;
            while(ele > 1LL){
                ll left = (ele+1)/2;
                ll right = ele - 1;
                currOps += (cnt*(occ[right]-occ[left-1]));       
                ele = left;
                cnt++;
            }
            ele = i;
            cnt = 1LL;
            while(ele < MAX){
                ll left = ele + 1;
                ll right = min(ele*2, MAX);
                currOps += (cnt*(occ[right]-occ[left-1]));
                ele = right;
                cnt++;
            }
            minOps = min(minOps, currOps);
        }
        
        cout<<minOps<<"\n";
        
     }
  
return 0;
}