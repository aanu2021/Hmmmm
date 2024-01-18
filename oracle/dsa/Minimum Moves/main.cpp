#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int count(int a, int b) {
    int cnt = 0;
    string strA = to_string(a);
    string strB = to_string(b);

    for (int i = 0; i < strA.length(); ++i) {
        cnt += abs(strA[i] - strB[i]);
    }

    return cnt;
}

int find(vector<int>a,vector<int>b){
    int ans=0;
    for(int i=0;i<a.size();i++){
        ans += count(a[i],b[i]);
    }
    return ans;
}

int main() {
    
    vector<int>a={1234,4321};
    vector<int>b={2345,3214};
    
    cout<<find(a,b);

    return 0;
}