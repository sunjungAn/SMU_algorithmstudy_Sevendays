#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector < pair<int, pair<int, int>>> v; //가중치, 시작 정점, 끝 정점 
int parent[1000001]; // 부모 넣을 벡터
int numv, nume;
void input(void)
{
	//정점의 개수와 간선의 개수 
	cin >> numv >> nume;
	for (int i = 0; i < numv; i++)
		parent[i] = i;
	for (int i = 0; i < nume; i++)
	{
		int  s, e, w; // 가중치, 처음 정점, 끝정점
		cin >> s>> e >> w;
		v.push_back({ w, {s, e} });

	}
	sort(v.begin(), v.end()); //가중치를 기준으로 정렬
}

int find(int v)
{
	if (parent[v] == v) //부모와 자식이 같으면
		return v;
	else
		return find(parent[v]); //다르면 부모의 부모를 찾음
}
void union_(int v1, int v2)
{
	int x, y;
	x = find(v1);  // 부모 정점 찾기
	y = find(v2);
	
	if (x < y)
		parent[y] = x;
	else
		parent[x] = y;
}
int main(void)
{
	input();
	int maxnum = v[0].first;
	int answer = 0;
	for (int i = 0; i< v.size(); i++)
	{
		if (find(v[i].second.first) != find(v[i].second.second)) //사이클이 없으면
		{
			union_(v[i].second.first, v[i].second.second);
			maxnum = max(maxnum, v[i].first);
			cout << v[i].first << '\n';
			answer += v[i].first;
		}
	}
	cout << answer - maxnum << '\n';
	return 0;
	
}