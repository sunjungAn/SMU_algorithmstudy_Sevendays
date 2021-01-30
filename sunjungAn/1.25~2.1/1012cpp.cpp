#include<iostream>
#include<cstring>
using namespace std;
short map[52][52];
bool visit[52][52];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
int T;
int M, N, K;

void input()
{
	int x, y;
	cin >> M >> N>>K;
	for (int i = 0; i < K; i++)
	{
		cin >> x >> y;
		map[y][x] = 1;
	}
}

void dfs(int a, int b)
{
		visit[a][b] = true;
		for (int i = 0; i < 4; i++)
		{
			if(map[a+dx[i]][b+dy[i]]==1 && visit[a+dx[i]][b+dy[i]]==false)
				dfs(a + dx[i], b + dy[i]);
		}
}

int count()
{
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if ((map[i][j] == 1) && (visit[i][j] == false)) {
				dfs(i, j);
				ans++;
			}
				
		}
	}
	return ans;
}
int main(void)
{
	cin >> T;
	for (int i = 0; i < T; i++) {
		input();
		cout << count() << '\n';
		memset(map, 0, sizeof(map));
		memset(visit, false, sizeof(visit));
	}
	
}