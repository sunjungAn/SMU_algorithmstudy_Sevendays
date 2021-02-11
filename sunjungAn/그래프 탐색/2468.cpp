#include<iostream>

using namespace std;
int map[101][101];
bool visit[101][101];
int N;
int dx[] = { -1, 1, 0, 0 }, dy[] = { 0,0,-1, 1 };

void dfs(int i, int j)
{
	visit[i][j] = false;
	
	for (int k = 0; k < 4; k++)
	{
		int nextx = i + dx[k];
		int nexty = j + dy[k];

		if (nextx >= 0 && nextx < N && nexty >= 0 && nexty < N && visit[nextx][nexty] == true)
			dfs(nextx, nexty);
	}
}
int main(void)
{
	int max = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	for (int k = 0; k < 101; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] > k) //안전지대를 true
				{
					visit[i][j] = true;
				}
			}
		}
		int ans = 0;
		for(int i = 0; i<N; i++)
			for(int j = 0; j<N; j++)
				if (visit[i][j] == true) {
					dfs(i, j);
					ans++;
				}
	//	cout << ans << "\n";
		if (ans == 0)
			break;
		if (ans > max)
			max = ans;

	}
	cout << max;
}