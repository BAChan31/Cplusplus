#include <iostream>
using namespace std;

int max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	int testCase;
	cin >> testCase;
	
	int arr[10001];
	int dp[10001];

	for (int i = 0; i < testCase; i++)
		cin >> arr[i];

	int temp = 0;

	for (int i = 0; i < testCase; i++)
	{
		if (i == 0)
			dp[0] = arr[0];
		else if (i == 1)
			dp[1] = dp[0] + arr[1];
		else if (i == 2)
		{
			dp[2] = max(dp[0] + arr[2], arr[1] + arr[2]);
			dp[2] = max(dp[2], dp[1]);
		}
		else
		{
			dp[i] = max(dp[i - 3] + arr[i-1] + arr[i],dp[i-2] + arr[i]);
			dp[i] = max(dp[i], dp[i - 1]);
		}
		temp = max(temp, dp[i]);
	}


	cout << temp << endl;

	return 0;
}