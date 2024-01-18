int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    priority_queue<pair<int,int>>pq;
    for(vector<int>x : boxTypes)
        pq.push({x[1],x[0]});
    int cnt=0;
    int units=0;
    while(!pq.empty() && cnt<truckSize){
        if(cnt+pq.top().second<truckSize){
            cnt+=pq.top().second;
            units+=pq.top().second*pq.top().first;
            pq.pop();
        }
        else{
            int q=truckSize-cnt;
            cnt+=q;
            units+=q*pq.top().first;
            pq.pop();
        }
    }
    return units;
}