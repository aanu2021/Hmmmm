struct Pair{
    int cost;
    int index;
    int grp;
};

class Solution {
public:
    typedef long long ll;
    struct comp{
      bool operator()(const Pair&x,const Pair&y){
          if(x.cost==y.cost){
              return x.index > y.index;
          }
          return x.cost > y.cost;
      }  
    };
    long long totalCost(vector<int>& costs, int c, int k) {
        int n = costs.size();
        priority_queue<Pair,vector<Pair>,comp>pq;
        for(int i=0;i<k;i++){
            pq.push({costs[i],i,1});
        }
        for(int i=n-1;i>=max(n-k,k);i--){
            pq.push({costs[i],i,2});
        }
        ll sum = 0LL;
        int L = k;
        int R = n-k-1;
        while(!pq.empty() && c>0){
            auto curr=pq.top();
            pq.pop();
            c--;
            int cost=curr.cost;
            int grp=curr.grp;
            sum+=(ll)cost;
            if(grp==1){
                if(L<=R){
                    pq.push({costs[L],L,1});
                    L++;
                }
            }else{
                if(L<=R){
                    pq.push({costs[R],R,2});
                    R--;
                }
            }
        }
        return sum;
    }
};