#include <iostream>
using namespace std;

int arr[1001][1001];
bool visit[1001];
int N, M;
void dfs(int start) {
	visit[start] = true;
	for (int i = 1; i <= N; i++)
	{
		if (arr[start][i] == 1 && visit[i] == false)
			dfs(i);
	}
}

int main() {
	int result=0;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		arr[u][v] = arr[v][u] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		if (visit[i] == false)
		{
			dfs(i);
			result++;
		}
	}

	cout << result << endl;
}