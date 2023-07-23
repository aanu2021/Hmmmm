// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

int findCount(int arr[], int N)
{
	// For storing number of pairs
	int ans = 0;

	// For storing count of numbers
	int bits[32] = { 0 };

	// Iterate from 0 to N - 1
	for (int i = 0; i < N; i++) {

		// Find the most significant bit
		int val = log2l(arr[i]);

		ans += bits[val];
		bits[val]++;
	}
	return N * (N - 1) / 2 - ans;
}

// Driver Code
int main()
{
	// Given array arr[]
	int arr[] = { 1, 2, 3, 4, 5, 6 };

	int N = sizeof(arr) / sizeof(arr[0]);

	// Function Call
	cout << findCount(arr, N);

	return 0;
}
