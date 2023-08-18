class Solution {
public:
    
    typedef long long ll;
    
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        
        int n = basket1.size();
        
        unordered_map<int,int>f1,f2;
        
        for(int ele:basket1){
            f1[ele]++;
        }
        for(int ele:basket2){
            f2[ele]++;
        }
        
        for(auto &itr:f1){
            int ele = itr.first;
            int occ = min(f1[ele],f2[ele]);
            f1[ele] -= occ; f2[ele] -= occ;
        }
        
        for(auto &itr:f2){
            int ele = itr.first;
            int occ = min(f1[ele],f2[ele]);
            f1[ele] -= occ; f2[ele] -= occ;
        }
        
        for(auto &itr:f1){
            if(itr.second%2) return -1;
        }
        for(auto &itr:f2){
            if(itr.second%2) return -1;
        }
        
        vector<int>v1,v2;
        
        for(auto &itr:f1){
            int occ = (itr.second/2);
            for(int num=1;num<=occ;num++) v1.push_back(itr.first);
        }
        for(auto &itr:f2){
            int occ = (itr.second/2);
            for(int num=1;num<=occ;num++) v2.push_back(itr.first);
        }
        
        sort(v1.begin(),v1.end());
        sort(v2.rbegin(),v2.rend());
        
        ll ans = 0LL;
        ll mini = 1e18;
        
        for(int ele:basket1){
            mini = min(mini,(ll)ele);
        }
        for(int ele:basket2){
            mini = min(mini,(ll)ele);
        }
        
        int sz = v1.size();
        
        for(int i=0;i<sz;i++){
            ans += min({(ll)v1[i],(ll)v2[i],2LL*mini});
        }
        
        return ans;
        
    }
};