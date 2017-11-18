#include <iostream>
using namespace std;

int main() {
	int testCase;
	cin >> testCase;
	int temp = testCase-1;
	long long int dp[31][31] = {};

	for (int i = 0; i < 31; i++)
	{
		dp[i][0] = 1;
		dp[i][i] = 1;
	}
	for (int i = 1; i < 31; i++)
	{
		for (int j = 1; j < i; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i-1][j];
		}
	}

	while (testCase > 0)
	{
		int N, M;
		cin >> N >> M;
		cout << dp[M][N] << endl;
		testCase--;
	}

	return 0;
}