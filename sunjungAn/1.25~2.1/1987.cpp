#include<iostream>
#include<stack>
#include<string>


using namespace std;

char map[22][22]; //바둑판
int R, C;
int maxlen;
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
bool alpha[26];
int nextx, nexty;

void input()
{
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
			cin >> map[j][i];
	}
}

void backtraking(int x, int y, int len)
{
	if (alpha[map[x][y] - 'A']) //있으면
		return;
	
	//없으면
	alpha[map[x][y] - 'A'] = true;
	maxlen = (maxlen < len) ? len : maxlen;
	for (int i = 0; i < 4; i++)
	{
		nextx = x + dx[i];
		nexty = y + dy[i];

		if (map[nextx][nexty] != 0)
			backtraking(nextx, nexty, len + 1);
	}
	alpha[map[x][y] - 'A'] = false;
}

int main(void)
{
	input();
	backtraking(1,1,1);
	cout << maxlen;
}