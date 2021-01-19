#include<iostream>
using namespace std;
int N;
int ans[3];
short map[2200][2200];
int maski(int x, int y, int n);

void divide(int x, int y, int n)
{
	if (n < 3)
	{
		for (int i = x; i < x + n; i++)
		{
			for (int j = y; j < y + n; j++)
			{
				ans[map[i][j] + 1]++; //-1은 0인덱스, 0은 1인덱스, 1은 2인덱스에 넣는다. 
			}
		}
	}
	else {
		int c = maski(x, y, n);
		if (c != -10) // 완전한 종이일 경우
			ans[c + 1]++;
		else {
			n = n / 3;
			divide(x, y, n);
			divide(x + n, y, n);
			divide(x + n + n, y, n);
			divide(x, y + n, n);
			divide(x + n, y + n, n);
			divide(x + n + n, y + n, n);
			divide(x, y + n + n, n);
			divide(x + n, y + n + n, n);
			divide(x + n + n, y + n + n, n);
		}
	}
}
int maski( int x, int y, int n)
{
	short a = map[x][y]; //첫 만날 원소
	for (int i = x; i < x + n; i++)
	{
		for (int j = y; j < y + n; j++)
		{
			if (a != map[i][j]) //다르면
				return -10;
		}
	}
	return a; //같으면 -1, 0, 1중에 리턴
}


int main(void)
{
	cin >> N;
	short k;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> k;
			map[i][j] = k;
		}
	}

	divide(0, 0, N);
	cout << ans[0] << '\n' << ans[1] << '\n' << ans[2] << '\n';
}
