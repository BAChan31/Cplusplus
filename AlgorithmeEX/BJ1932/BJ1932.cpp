#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int triangleNumber;
	cin >> triangleNumber;

	int** arr = new int *[triangleNumber+1];
	int** dp = new int *[triangleNumber + 1];

	for (int i = 1; i <= triangleNumber; i++)
	{
		arr[i] = new int[i];
		dp[i] = new int[i];
		for (int j = 0; j < i; j++)
		{
			cin >> arr[i][j];
		}
	}	

	dp[1][0] = arr[1][0];

	for (int i = 2; i <= triangleNumber; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j] + arr[i][j];
			}
			else if (j == i - 1)
			{
				dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
			}
		}
	}

	int temp = 0;
	for (int i = 0; i < triangleNumber; i++)
	{
		temp = max(temp, dp[triangleNumber][i]);
	}

	cout << temp << endl;

	return 0;
}