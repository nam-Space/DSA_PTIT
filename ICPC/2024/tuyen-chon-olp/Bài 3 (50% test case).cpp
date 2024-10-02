#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1001][1001], b[1001][1001];

int getDuongCheo(int i, int j)
{
	if (a[i][j] == 1)
	{
		if (b[i][j] != 1 && b[i + 1][j + 1] != 1)
		{
			b[i][j] = b[i + 1][j + 1] = 1;
			return 1;
		}
	}
	if (a[i][j] == 2)
	{
		if (b[i][j + 1] != 1 && b[i + 1][j] != 1)
		{
			b[i][j + 1] = b[i + 1][j] = 1;
			return 1;
		}
	}
	if (a[i][j] == 3)
	{
		if (b[i][j] != 1 && b[i + 1][j + 1] != 1 && b[i][j + 1] != 1 && b[i + 1][j] != 1)
		{
			b[i][j] = b[i + 1][j + 1] = b[i][j] = b[i + 1][j + 1] = 1;
			return 2;
		}
		if (b[i][j] != 1 && b[i + 1][j + 1] != 1)
		{
			b[i][j] = b[i + 1][j + 1] = 1;
			return 1;
		}
		if (b[i][j + 1] != 1 && b[i + 1][j] != 1)
		{
			b[i][j + 1] = b[i + 1][j] = 1;
			return 1;
		}
	}
	return 0;
}

int main()
{
	memset(b, 0, sizeof(b));
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			sum += getDuongCheo(i, j);
		}
	}
	cout << sum << endl;
}
