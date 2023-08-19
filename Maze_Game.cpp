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
             
            int n,m;
            cin>>n>>m;
            
            vector<ll>T(n+1);
            vector<ll>start(m+1);
            vector<ll>end(m+1);
            vector<ll>len(m+1);
            vector<vector<pair<ll,ll>>>graph(n+1);
            
            for(ll i=1;i<=n;i++){
                cin>>T[i];
            }
            
            for(ll i=0;i<m;i++){
                cin>>start[i];
            }
            for(ll i=0;i<m;i++){
                cin>>end[i];
            }
            for(ll i=0;i<m;i++){
                cin>>len[i];
            }
            
            for(ll i=0;i<m;i++){
                graph[start[i]].push_back({end[i],len[i]});
                graph[end[i]].push_back({start[i],len[i]});
            }
            
            vector<bool>visited(n+1,false);
            priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
            pq.push({0LL,1LL});
            
            vector<ll>dist(n+1,1e16);
            dist[1] = 0LL;
            
            while(!pq.empty()){
                auto curr = pq.top(); pq.pop();
                ll wt = curr.first;
                ll node = curr.second;
                if(visited[node]) continue;
                visited[node] = true;
                dist[node] = wt;
                for(auto &nbrs : graph[node]){
                    ll nbr = nbrs.first;
                    ll edgeWt = nbrs.second;
                    if(visited[nbr]) continue;
                    ll newEdgeWt = dist[node] + edgeWt;
                    if(dist[nbr] > newEdgeWt && newEdgeWt < T[nbr]){
                        dist[nbr] = newEdgeWt;
                        pq.push({dist[nbr],nbr});
                    }
                }
            }
            
            for(ll i=1;i<=n;i++){
                if(dist[i] == 1e16) dist[i] = -1LL;
            }
            
            for(ll i=1;i<=n;i++){
                cout<<dist[i]<<" ";
            }cout<<"\n";
            
         }
      
    return 0;
    
}