#include<iostream>
#include<queue>

using namespace std;

int map[9][9];
int N, M;
int T;
int c;
int ans;
int res;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
int one;


void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				one++;
		}
	}
}
int bfs()
{
	bool visit[9][9];
	memset(visit, 0, sizeof(visit));
	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
		///	cout << map[i][j] << " ";
			if (map[i][j] == 2) {
				q.push(make_pair(i, j));
			}
			else if (map[i][j] == 1)
				visit[i][j] = true;
		}
		//cout << "\n";
	}
	int two = 0;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		//cout << x << " " << y<<"\n";
		visit[y][x] = 1;
		//cout << visit[y][x] << "\n";
		two++;

		for (int i = 0; i < 4; i++)
		{
			int nextx = x + dx[i];
			int nexty = y + dy[i];
			if ((nextx>=0) && (nexty >= 0) && (nextx < M) &&(nexty <N)&& (visit[nexty][nextx] == 0))
				q.push(make_pair(nexty, nextx));
		}
		q.pop();
	}
	int r = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visit[i][j] == 0)
				r++;
		}
			
		//cout << "\n";
	}
	//cout << r << "\n";
	return r;
}

int main(void)
{
	input();
	T = N * M;

	for (int i = 0; i < T-2; i++)
	{
		if (map[i / M][i % M] != 0)
			continue;
		else {
			map[i / M][i % M] = 1;
			for (int j = i+1; j < T - 1; j++)
			{
				if (map[j / M][j % M] != 0)
					continue;
				else {
					map[j / M][j % M] = 1;
					for (int k = j + 1; k < T; k++)
					{
						if (map[k / M][k % M] == 0){
							map[k / M][k % M] = 1;
							res = bfs();
							ans = (ans > res) ? ans : res;
							map[k / M][k % M] = 0;
						
						}
					}
					map[j / M][j % M] = 0;
				}
			}
			map[i / M][i % M] = 0;
		}
	}
	cout << ans;

}
