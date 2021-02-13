#include<iostream>
#include<cstdio>
using namespace std;
int N;
char map[101][101];
bool visit[101][101];
int ans1, ans2;
int dx[] = { -1, 1, 0, 0 }, dy[] = { 0,0,-1,1 };


void bfs1(int i, int j, char c)
{
	visit[i][j] = true;

	for (int k = 0; k < 4; k++)
	{
		int nextx = i + dx[k];
		int nexty = j + dy[k];
		if (nextx >= 0 && nextx < N && nexty >= 0 && nexty < N && visit[nextx][nexty] == false && map[nextx][nexty] == c)
			bfs1(nextx, nexty, c);
	}

}
void bfs2(int i, int j)
{
	visit[i][j] = true;

	for (int k = 0; k < 4; k++)
	{
		int nextx = i + dx[k];
		int nexty = j + dy[k];
		if (nextx >= 0 && nextx < N && nexty >= 0 && nexty < N && visit[nextx][nexty] == false && map[nextx][nexty] != 'B')
			bfs2(nextx, nexty);
	}
}

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j] == false)
			{
				bfs1(i, j, map[i][j]);
				ans1++;
			}
		}
	}
	cout << ans1 << " ";
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visit[i][j] = false;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j] == false && map[i][j] == 'B')
			{
				bfs1(i, j, 'B');
				ans++;
			}
			else if(visit[i][j] == false){
				bfs2(i, j);
				ans++;
			}
		}
	}
	cout << ans ;

}