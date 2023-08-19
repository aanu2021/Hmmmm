#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void MIN(int &x,int y){
    if(y >= 0 && (x < 0 || x > y)){
        x = y;
    }
}

int main(){
     
         ios_base::sync_with_stdio(false);
         cin.tie(NULL);
         cout.tie(NULL);
     
         int t=1;
        //  cin>>t;
         
         while(t--){
             
            string s;
            cin>>s;
            
            int n = s.length();
            
            // dp[i][j][0/1] -> i-th index, j-th character, prefix is good or not 
            int dp[n+1][26][2];
            memset(dp,-1,sizeof(dp));
            
            for(int i=0;i<26;i++){
                dp[0][i][0] = abs(i-(int)(s[0]-'a'));
            }
            
            
            // traverse each index of the string
            for(int i=1;i<n;i++){
                
                int x = (int)(s[i]-'a');
                // cout<<x<<"\n";
                
                // explore all possible previous indexed characters
                for(int j=0;j<26;j++){
                    
                   // whether s[0...i-1] string is good or not    
                   for(int k=0;k<2;k++){
                       
                       if(dp[i-1][j][k] < 0) continue;
                       
                       // Good String formation at i-th index
                       MIN(dp[i][j][1], dp[i-1][j][k] + abs(x-j));
                       
                       if(k==1){
                           // Start a not-good string from i-th index 
                           for(int y=0;y<26;y++){
                               if(y != j){
                                   MIN(dp[i][y][0], dp[i-1][j][k] + abs(x-y));   
                               }
                           }   
                       }
                       
                   }
                    
                }
                
            }
            
            int mini = 1e9;
            
            // for(int i=0;i<n;i++){
            //     cout<<dp[i][1][0]<<" "<<dp[i][1][1]<<"\n";
            // }
            
            for(int i=0;i<26;i++){
                if(dp[n-1][i][1] == -1) continue;
                // cout<<dp[n-1][i][1]<<"\n";
                mini = min(mini, dp[n-1][i][1]);
            }
            
            cout<<mini<<"\n";
            
         }
      
    return 0;
    
}