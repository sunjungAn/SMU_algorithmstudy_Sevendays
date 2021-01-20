#include <iostream>
using namespace std;

// 한 줄로 서기
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N, left;
	int arr[10] = { 0, };

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> left;
		for (int j = 0; j < N; j++) {
			if (left == 0 && arr[j] == 0) { // 키 큰 사람들을 지나쳤고 위치하고자 하는 자리가 비어있다면
				arr[j] = i + 1; // arr[j]는 자신의 위치, i+1은 키
				break;
			}
			else if (arr[j] == 0) { // 키 큰 사람이 남아있다면
				left--;
			}
		}
	}
	for (int i = 0; i < N; i++)
		cout << arr[i] << ' ';
	return 0;
}
