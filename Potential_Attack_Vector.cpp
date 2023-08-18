#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	
	int n;
	cin>>n;
	
	vector<int>a(n);
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	
	int q;
	cin>>q;
	
	vector<vector<int>>queries(q,vector<int>(2));
	
	for(int i=0;i<q;i++){
	    cin>>queries[i][0]>>queries[i][1];
	}
	
	int MAX = 0;
	
	for(int i=0;i<n;i++){
	    MAX = max(MAX,a[i]);
	}
	for(int i=0;i<q;i++){
	    MAX = max(MAX,queries[i][1]);
	}
	
	unordered_map<int,int>freq;
	
	for(int i=0;i<n;i++) freq[a[i]]++;
	
	vector<int>prefix(MAX+1,0);
	
	for(int i=1;i<=MAX;i++){
	    for(int j=i;j<=MAX;j+=i){
	        prefix[i] += freq[j];
	    }
	}
	
	for(int i=1;i<=MAX;i++){
	    ll ele = (ll)prefix[i];
	    ll currSum = (ele*(ele-1));
	    currSum += ele;
	    prefix[i] = currSum;
	    prefix[i] += prefix[i-1];
	}
	
	vector<ll>answer(q,0LL);
	
	for(int i=0;i<q;i++){
	    ll ele = prefix[queries[i][1]] - prefix[queries[i][0]-1];
	    answer[i] = ele;
	}
	
	for(int i=0;i<q;i++){
	    cout<<answer[i]<<" ";
	}cout<<"\n";
	
	return 0;
}