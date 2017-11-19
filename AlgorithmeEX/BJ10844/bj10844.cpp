#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<vector<int>> dp(N, vector<int>(10, 0));
	dp[0] = { 0,1,1,1,1,1,1,1,1,1 };

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][1];
			else if (j == 9)
				dp[i][j] = dp[i - 1][8];
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j+1]) % 1000000000;
		}
	}

	int result = 0;
	for (int x : dp[N - 1])
		result = (result + x) % 1000000000;

	cout << result << endl;

	return 0;
}