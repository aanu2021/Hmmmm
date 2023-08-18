#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n,k;
	cin>>n>>k;
	
	string s;
	cin>>s;
	
	int minLen = n+1;
	
	int l = 0, r = 0;
	string minStr = "";
	
	int cnt = 0;
	
	while(r<n){
	    cnt += (s[r]=='1' ? 1 : 0);
	    while(l <= r && cnt==k){
	        int currLen = (r-l+1);
	        if(currLen < minLen){
	            minLen = currLen;
	            minStr = s.substr(l,currLen);
	        }
	        else if(currLen == minLen){
	            minStr = min(minStr,s.substr(l,currLen));
	        }
	        cnt -= (s[l]=='1' ? 1 : 0);
	        l++;
	    }
	    r++;
	}
	
	cout<<minStr<<"\n";
	
	return 0;
}