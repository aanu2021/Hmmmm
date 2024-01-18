#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> frequencyOfMaxValue(vector<int> numbers, vector<int> q)
{
    int n = numbers.size();
    vector<int> answer(n, -1);
    int maxvalue = -1, count = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (numbers[i] == maxvalue)
        {
            count++;
        }
        if (numbers[i] > maxvalue)
        {
            maxvalue = numbers[i];
            count = 1;
        }
        answer[i] = count;
    }

    vector<int> result;
    for (int index : q)
    {
        result.push_back(answer[index - 1]);
    }

    return result;
}

int main()
{
    vector<int> nums = {5, 4, 5, 3, 2};
    vector<int> query = {1, 2, 3, 4, 5};

    vector<int> result = frequencyOfMaxValue(nums, query);

    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
