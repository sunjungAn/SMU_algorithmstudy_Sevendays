//ATM : 1시간 소요
#include<iostream>
#include<vector>
using namespace std;
int arr[1001];
vector<long long> v;
int main(void)
{
	int N;
	cin >> N;
	int w;
	for (int i = 0; i < N; i++) {
		cin >> w;
		arr[w]++;
	}
	v.push_back(0);
	int k = 1;
	for (int i = 1; i < 1001; i++)
	{
		for (int j = 0; j < arr[i]; j++) //0, 1
		{
			v.push_back(i + v[k - 1]);
			k++;
		}
	}
	long long ans = 0; 
	for (int k = 1; k < v.size(); k++)
	{
		ans += v[k];
	}
	
	cout << ans;

}
