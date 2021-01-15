#include<iostream>
using namespace std;

int arr[10001];
int N;
int maxw;

int main(void)
{
	cin >> N;
	int temp = N;
	int w;
	for (int i = 0; i < N; i++)
	{
		cin >> w;
		arr[w]++;
	}
	for (int i = 1; i<10001; i++)
	{
		if (arr[i] != 0)
		{
			w = arr[i];
			arr[i] = temp;
			temp -= w;
		}
	}
	for (int i = 1 ; i < 10001; i++)
	{
		if (arr[i] != 0) {
			if (maxw < arr[i] * i)
				maxw = arr[i] * i;
		}
	}
	cout << maxw;
}
