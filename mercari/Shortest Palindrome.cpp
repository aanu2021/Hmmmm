#include<bits/stdc++.h>
using namespace std;

int findLPS(string &s){
    
    int n = s.length();
    
    vector<int>lps(n, 0);
    
    for(int i=1;i<n;i++){
        int len = lps[i-1];
        while(len > 0 && s[len] != s[i]){
            len = lps[len-1];
        }
        if(s[len] == s[i]){
            len++;
        }
        lps[i] = len;
    }
    
    return lps[n-1];
}

int main(){
    
    string s;
    cin>>s;
    
    string rev = s;
    reverse(rev.begin(),rev.end());
    
    string str = s;
    str += "#";
    str += rev;
    
    int len = findLPS(str);
    
    cout<<(s.length() - len)<<"\n";
    
    return 0;
    
}