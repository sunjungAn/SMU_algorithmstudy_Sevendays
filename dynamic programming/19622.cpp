#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

long long dp[100001];
long long cost[100001];
vector <pair<int, int>> v;
long long c;

void input(void)
{
	cin >> c;
	v.push_back({ 0, 0 });
	for (long long i = 1; i <= c; i++)
	{
		long long start, end, w;
		cin >> start >> end >> w;
		v.push_back({ start, end });
		cost[i] = w;
	}
	//sort(v.begin(), v.end());
}

int main(void)
{
	input();
	for (int i = 3; i <= c; i++)
	{
		cost[i] = cost[i]+ max( cost[i - 2] , cost[i - 3]);
	}
	cout << max(cost[c], cost[c - 1])<< '\n';


}