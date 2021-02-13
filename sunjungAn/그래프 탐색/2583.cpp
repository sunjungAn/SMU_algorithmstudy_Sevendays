#include<iostream>
#include<queue>
using namespace std;


bool map[101][101];
int dx[] = { -1,1, 0, 0 }, dy[] = { 0,0,-1, 1 };
int N, M, K;
int ans;


std::priority_queue<int, std::vector<int>, greater<int> >q;

void bfs(int i, int j)
{
	map[i][j] = true;
	ans++;

	for (int k = 0; k < 4; k++)
	{
		int nextx = i + dx[k];
		int nexty = j + dy[k];
		if (nextx >= 0 && nextx < N && nexty >= 0 && nexty < M && map[nextx][nexty] == false)
		{
			bfs(nextx, nexty);
		}
	}

}
int main(void)
{
	int x1, y1, x2, y2;
	
	int res = 0;
	cin >> N >> M >> K; //N = 5 M = 7
	for (int i = 0; i < K; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2; 
 		for (int i = x1; i <= x2-1; i++)  // 0 1 2 3
			for (int j = y1; j <= y2 - 1; j++) // 1 2
				map[j][i] = true;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == false)
			{
				res++;
				bfs(i, j);
				q.push(ans);
				ans = 0;
			}
			else
				continue;
		}
	}
	cout << res << '\n';
	while (!q.empty()) {
		cout << q.top() << ' ';
		q.pop();
	}

}