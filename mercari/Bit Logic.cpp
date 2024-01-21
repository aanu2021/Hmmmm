#include<bits/stdc++.h>
using namespace std;

struct Node{
     Node*links[2];
     Node(){
         links[0] = NULL;
         links[1] = NULL;
     }
     bool containsKey(int val){
         return (links[val] != NULL);
     }
     void put(int val, Node * node){
         links[val] = node;
     }
     Node * get(int val){
         return links[val];
     }
};

int mx = 0;

Node * root = new Node();

void insert(int num){
    Node * node = root;
    for(int i=31;i>=0;i--){
        int bit = 0;
        if((num&(1<<i))) bit = 1;
        if(!node->containsKey(bit)){
            node->put(bit, new Node());
        }
        node = node->get(bit);
    }
}

void recursion(int i,bool &flag,Node * node, int xorSum, int num, int k){
    if(xorSum > k) return;
    if(i < 0){
        mx = max(mx, xorSum);
        flag = true;
        return;
    }
    if(flag) return;
    int bit = 0;
    if((num&(1<<i))) bit = 1;
    if(node->containsKey(1 - bit)){
        recursion(i-1,flag,node->get(1-bit),(xorSum|(1<<i)),num,k);
    }
    if(flag) return;
    if(node->containsKey(bit)){
        recursion(i-1,flag,node->get(bit),xorSum,num,k);
    }
    if(flag) return;
}

int main(){
    
    int low, high, k;
    cin>>low>>high>>k;
    
    for(int i=low;i<=high;i++){
        insert(i);
    }
    
    int maxSum = 0;
    for(int i=low;i<=high;i++){
        mx = 0;
        bool flag = false;
        Node * node = root;
        recursion(31,flag,node,0,i,k);
        maxSum = max(maxSum, mx);
    }
    
    cout<<maxSum<<"\n";
    
    return 0;
}