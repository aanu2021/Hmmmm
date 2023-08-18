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
            
            vector<ll>a(n+1);
            for(ll i=1;i<=n;i++){
                cin>>a[i];
            }
            
            ll k;
            cin>>k;
            
            vector<ll>cycle;
            vector<bool>visited(n+1,false);
            
            ll src = 1LL;
            while(visited[src]==false){
                cycle.push_back(src);
                visited[src] = true;
                src = a[src];
            }
            
            ll m = cycle.size();
            
            if(src == 1LL){
                ll temp = cycle[0];
                reverse(cycle.begin(),cycle.end());
                cycle.pop_back();
                reverse(cycle.begin(),cycle.end());
                cycle.push_back(temp);
                k--;
                ll index = (k%m);
                cout<<cycle[index]<<"\n";   
            }
            else{
                reverse(cycle.begin(),cycle.end());
                cycle.pop_back();
                reverse(cycle.begin(),cycle.end());
                m = cycle.size();
                ll cnt = 0LL;
                ll idx = -1LL;
                for(ll i=0;i<m;i++){
                    if(cycle[i] != src){
                        cnt++;
                    }
                    else{
                        idx = i;
                        break;
                    }
                }
                if(k <= cnt){
                    cout<<cycle[k-1]<<"\n";
                }
                else{
                    k -= cnt;
                    ll rem = (m-cnt);
                    vector<ll>arr;
                    for(ll i=idx;i<m;i++){
                        arr.push_back(cycle[i]);
                    }
                    m = rem;
                    ll index = (k%m);
                    if(index==0) index = m;
                    cout<<arr[index-1]<<"\n";
                }
            }
            
         }
      
    return 0;
    
}