vector<int> autocomplete(vector<string> command) {
    int size = command.size();
    vector<int> ans(size);

    unordered_map<string, int> memo;
    for(int i = 0; i < size; i++)
    {
        string temp = "";
        int n = 0;
        for(auto x: command[i])
        {
            temp = temp + x;
            if(memo[temp]){
                n = memo[temp];
            }
            memo[temp] = i + 1;
        }
        ans[i] = (n == 0 && i != 0)?(i):(n);        
    }
    return ans;
}