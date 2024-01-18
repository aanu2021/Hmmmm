#include<bits/stdc++.h>
using namespace std;
#define ll long long
  
int find(int n,int d,int k,vector<int>s,vector<int>e,vector<int>p){
    int ans = 0;
    for (int i = 0; i < n; i++){  
        int day = s[i]; 
        int cnt = 0; 
        priority_queue<int>values; 
        for (int j = 0; j < n; j++){	  
            if (s[i] >= s[j] && s[i] <= e[j]){
                values.push (p[j]);
            }
            
        }
         
        int t = k;
              
        while (t-- && !values.empty ()){
            cnt += values.top ();
            values.pop ();
        }  
        ans = max (ans, cnt);  
    }
    return ans;
}
 
int main (){
    int n=4;
    int d=10;
    int k=3;
      
    vector<int>s={2, 4, 6, 3};
    vector<int>e={8, 9, 7, 5};
    vector<int>p={900, 1600, 2000, 400}; 
    
    cout << find(n,d,k,s,e,p) << "\n";
}
