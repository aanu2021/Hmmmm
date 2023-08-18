#include <bits/stdc++.h>
using namespace std;

class Node{
   public:
   string key;
   Node*next;
   Node*prev;
   Node(string key){
       this->key = key;
       this->next = NULL;
       this->prev = NULL;
   }
};

class LRUCache{
    public:
    Node*head;
    Node*tail;
    int capacity;
    unordered_map<string,Node*>keyNode;
    LRUCache(int capacity){
        this->capacity = capacity;
        this->head = new Node("$#@");
        this->tail = new Node("$#@");
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node*node){
        Node*prevNode = tail->prev;
        Node*nextNode = tail;
        prevNode->next = node;
        node->prev = prevNode;
        node->next = nextNode;
        nextNode->prev = node;
    }
    void removeNode(Node*node){
        Node*prevNode = node->prev;
        Node*nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    // check cache hit/miss
    bool get(string key){
        if(keyNode.find(key) == keyNode.end()){
            return false;
        }
        Node*node = keyNode[key];
        removeNode(node);
        addNode(node);
        keyNode[key] = node;
        return true;
    }
    bool put(string key){
        if(keyNode.find(key) != keyNode.end()){
            Node*node = keyNode[key];
            removeNode(node);
            addNode(node);
            keyNode[key] = node;
            return true;
        }
        else{
            if(keyNode.size() == capacity){
                Node*node = head->next;
                keyNode.erase(node->key);
                removeNode(node);
            }
            Node*node = new Node(key);
            addNode(node);
            keyNode[key] = node;
            return false;
        }
    }
};

bool isPossible(vector<string>&vec,int n,int k,int capacity){
    LRUCache obj(capacity);
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(obj.put(vec[i]) == true){
            cnt++;
        }
    }
    return cnt >= k;
}

int main() {
	
	int n;
	cin>>n;
	
	vector<string>vec(n);
	for(int i=0;i<n;i++){
	    cin>>vec[i];
	}
	
	int k;
	cin>>k;
	
	int low = 1, high = n;
	int ans = -1;
	
	while(low <= high){
	    int mid = (low + high)/2;
	    if(isPossible(vec,n,k,mid)){
	        ans = mid;
	        high = mid - 1;
	    }
	    else{
	        low = mid + 1;
	    }
	}
	
	cout<<ans<<"\n";
	
	return 0;
}