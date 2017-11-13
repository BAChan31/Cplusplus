#include <iostream>
using namespace::std;

int main() {
	int nArray[11];
	int testCase;
	cin >> testCase;

	nArray[1] = 1;
	nArray[2] = 2;
	nArray[3] = 4;

	for (int i = 4; i < sizeof(nArray) / sizeof(int); i++)
		nArray[i] = nArray[i - 1] + nArray[i - 2] + nArray[i - 3];

	while (testCase > 0)
	{
		int tempN;
		cin >> tempN;
		cout << nArray[tempN] << "\n";
		testCase--;
	}

	return 0;
}
