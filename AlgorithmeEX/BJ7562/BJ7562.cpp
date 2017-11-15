#include <iostream>
#include <queue>
using namespace std;

static int moveX[] = {1,2,2,1,-1,-2,-2,-1};
static int moveY[] = {-2,-1,1,2,2,1,-1,-2};

void findWay(int length, int startX, int startY, int destX, int destY, int board[][300]) {
	queue<pair<int, int>> q;
	q.push({ startX, startY });

	while (!q.empty())
	{
		if (startX == destX && startY == destY)
		{
			q.pop();
			break;
		}

		for (int i = 0; i < 8; i++)
		{
			int nextX = q.front().first + moveX[i];
			int nextY = q.front().second + moveY[i];

			if (nextX >= 0 && nextY >= 0 && nextX < length && nextY < length && board[nextX][nextY] == 0)
			{
				board[nextX][nextY] = board[q.front().first][q.front().second] + 1;
				q.push({ nextX,nextY });
			}
		}
		q.pop();
	}
}

int main() {
	int testCase;
	cin >> testCase;

	int* result = new int[testCase];
	int temp = testCase;
	while (testCase > 0)
	{
		int length;
		cin >> length;

		int board[300][300] = {};

		int startX, startY;
		cin >> startX >> startY;

		int destinationX, destinationY;
		cin >> destinationX >> destinationY;

		findWay(length, startX, startY, destinationX, destinationY, board);

		result[temp - testCase] = board[destinationX][destinationY];
		testCase--;
	}

	for (int i = 0; i < temp; i++)
		cout << result[i] << endl;

	return 0;
}

