#include<iostream>
#include<queue>

using namespace std;
int N, M;
int min, max;
int visit[100001];
//maplen[100001];
int bfs()
{ // 4 27
	queue<int> q;
	q.push(N); 
	int x;
	int nextx;
	int len = 0;
	while (!q.empty())
	{
		x = q.front();
		len = visit[x];
		//cout << x << " " << len << "\n";
		if (x == M)
			break;
		if(x < 100001)
		{
			nextx = q.front()+1;
			if (nextx != N  && (visit[nextx] == 0 || visit[nextx] > len + 1)) {
				q.push(nextx);
				visit[nextx] = len + 1;
			}
			nextx = q.front()- 1;
			if ((nextx != N && nextx >= 0) && (visit[nextx] == 0 || visit[nextx] > len + 1)) {
				q.push(nextx);
				visit[nextx] = len + 1;
			}
			nextx = q.front()* 2;
			if (nextx != N  && (visit[nextx] == 0 || visit[nextx] > len + 1)) {
				q.push(nextx);
				visit[nextx] = len + 1;
			}

		}
		q.pop();
	}
	return visit[x];
}
int main(void)
{
	cin >> N >> M;
	if (N > M)
	{
		cout << N - M;
	}
	else cout << bfs();
	return 0;
}