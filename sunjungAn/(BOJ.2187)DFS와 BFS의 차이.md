+ DFS 는 깊이우선 탐색! --> 재귀를 통해 구현한다. 
+ BFS 는 너비우선 탐색 --> 반복문과 큐를 이용해 구현한다. 

## <최단 거리를 구할때는 보통 BFS를 사용한다>

### DFS로 2187을 구현했을 때

```
#include<iostream>
#include<cstdio>
using namespace std;
bool visit[102][102];
short map[102][102];
int minLen = 100000;
int N,M;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

void input()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf_s("%1d", &map[i][j]);
		}
	}
}

void dfs(int x, int y, int len)
{
	visit[x][y] = true;
	if (x == N && y == M)
	{
		minLen = (minLen > len) ? len : minLen;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int nextx = x + dx[i], nexty = y + dy[i];
		if ((map[nextx][nexty] == 0) || (visit[nextx][nexty] == true))
			continue;
		else {
			dfs(nextx, nexty, len + 1);
		}

	}
	visit[x][y] = false;
}

int main(void)
{
	input();
	dfs(1, 1, 1);
	cout << minLen;

}
```

> 구현은 되었지만 시간초과가 뜨게됨

### BFS로 2187을 구현했을 때

```
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

bool visit[102][102];
short map[102][102];
int minLen = 100000;
int N,M;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

void input()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
}

int bfs()
{
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair( 1,1 ), 1 ));
	int len = 0;

	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		len = q.front().second;
		if (x == N && y == M)
			break;
		//len = q.front().second;

		if (map[x][y] == 1 && visit[x][y] == false)
		{
			for (int i = 0; i < 4; i++)
			{
				visit[x][y] = true;
				int nextx = x + dx[i];
				int nexty = y + dy[i];
				if(map[nextx][nexty] == 1 && visit[nextx][nexty] == false)
					q.push(make_pair(make_pair(nextx, nexty), len + 1));
			}
		}
		q.pop();
	}
	return len;
}

int main(void)
{
	input();
	cout << bfs();

}
```
