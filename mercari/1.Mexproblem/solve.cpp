#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

int solve(vector<int> arr, int x)
{
    map<int, int> mp;
    int ans = INT32_MAX;
    int add = 0;

   
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i] % x]++;
    }

    
    for (auto i : mp)
    {
        ans = min(ans, i.second);
    }

    
    for (auto i : mp)
    {
        if (i.second - ans > 0)
        {
            add++;
        }
        else
        {
            break;
        }
    }

    
    return ans * x + add;
}

int main()
{
    
    vector<int> arr = {0,1,1,2,3};
    int x = 3;
    
    int result = solve(arr, x);

    cout << result << endl;

    return 0;
}
