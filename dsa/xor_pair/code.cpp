#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int countPairs = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int xorResult = arr[i] ^ arr[j];
            int andResult = arr[i] & arr[j];

            if (xorResult > andResult)
            {
                countPairs++;
            }
        }
    }

    cout << countPairs << endl;

    return 0;
}