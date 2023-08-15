#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll M = 1e9 + 7;

ll fact[200005];

bool prime[200005];

ll mod(ll a){
    return ((a%M)+M)%M;
}

ll mul(ll a,ll b){
    return mod(mod(a)*mod(b));
}

ll add(ll a,ll b){
    return mod(mod(a)+mod(b));
}

ll modPow(ll a,ll b){
    
    if(b==0){
        return 1LL;
    }
    
    else if(b==1){
        return a;
    }
    
    ll res=1LL;
    
    while(b){
        
        if(b%2==1){
            res=mul(res,a);
        }
        
        b/=2;
        a=mul(a,a);
        
    }
    
    return res;
    
}

ll inv(ll a){
    return modPow(a,M-2);
}

void factFind(){
    
    memset(fact,0LL,sizeof(fact));
    
    fact[0]=1LL;
    fact[1]=1LL;
    
    for(ll i=2;i<=200002;i++){
        fact[i]=mul(fact[i-1],i);
    }
    
}

ll nck(ll n,ll k){
    if(n < k) return 0LL;
    if(k==0) return 1LL;
    if(n==k) return 1LL;
    return mul(mul(fact[n],inv(fact[n-k])),inv(fact[k]));
}


int main(){
     
         ios_base::sync_with_stdio(false);
         cin.tie(NULL);
         cout.tie(NULL);
     
         int t=1;
        //  cin>>t;
        
         factFind();
         
         while(t--){
             
            string s;
            cin>>s;
            
            int n = s.length();
            
            vector<int>freq(26,0);
            for(int i=0;i<n;i++){
                freq[s[i]-'a']++;
            }
            
            sort(freq.begin(),freq.end());
            
            int maxFreq = freq[25];
            
            ll answer = 0LL;
            
            for(int k=1;k<=maxFreq;k++){
                int idx = lower_bound(freq.begin(),freq.end(),k) - freq.begin();
                ll curr = 1LL;
                if(idx == 26){
                    continue;
                }
                for(int j=idx;j<26;j++){
                    ll current = nck((ll)freq[j],(ll)k);
                    current++;
                    current %= M;
                    curr = mul(curr,current);
                }
                curr--;
                curr += M;
                curr %= M;
                answer += curr;
                answer %= M;
            }
            
            cout<<answer<<"\n";
            
         }
      
    return 0;
    
}