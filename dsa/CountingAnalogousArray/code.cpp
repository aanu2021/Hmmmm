#include <bits/stdc++.h>
using namespace std;
int countAnalogousArray(vector<int> consecutiveDifference, int lower, int upper)
{
    int maxy = INT_MIN;
    int mini = INT_MAX;
    int n = consecutiveDifference.size();
    if (consecutiveDifference[0] < 0)
    {
        int num = lower;
        for (int i = 0; i < n; i++)
        {
            num -= consecutiveDifference[i];
            if (num > upper || num < lower)
                return 0;
            maxy = max(maxy, num);
        }
        return upper - maxy + 1;
    }
    else
    {
        int num = upper;
        for (int i = 0; i < n; i++)
        {
            num -= consecutiveDifference[i];
            if (num > upper || num < lower)
                return 0;
            mini = min(mini, num);
        }
        return mini - lower + 1;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> consecutiveDifference;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        consecutiveDifference.push_back(a);
    }
    int lower, upper;
    cin >> lower >> upper;
    cout << countAnalogousArray(consecutiveDifference, lower, upper);
    return 0;
}