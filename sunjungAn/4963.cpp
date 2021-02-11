#include<iostream>
#include<queue>
using namespace std;
bool map[51][51];
int w, h;
short dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 }, dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

void dfs(int x, int y)
{
	map[x][y] = 0;
	for (int i = 0; i < 8; i++)
	{
		int nextx = x + dx[i], nexty = y + dy[i];
		if (nextx >= 0 && nextx < h && nexty >= 0 && nexty < w && map[nextx][nexty] == 1) {
			dfs(nextx, nexty);
		}
	}


}

int main(void)
{
	int ans;
	while (true)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			return 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		ans = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == 1)
				{
					dfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}


}