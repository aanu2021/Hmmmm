#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int numTestCases;
    cin >> numTestCases;

    for (int testCase = 1; testCase <= numTestCases; ++testCase)
    {
        int size;
        cin >> size;

        vector<int> arr(size);
        for (int i = 0; i < size; ++i)
        {
            cin >> arr[i];
        }

        // Calculate the sum of the elements in the vector
        int sum = 0;
        for (int i = 0; i < size; ++i)
        {
            sum += arr[i];
        }

        // Calculate the mean
        double mean = static_cast<double>(sum) / size;

        cout << mean << endl;
    }

    return 0;
}