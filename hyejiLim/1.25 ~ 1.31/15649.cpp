#include <iostream>
# include <algorithm>
using namespace std;
int arr[9] = { 0, };
int visit[9] = { 0, };
int N, M;

void backtracking(int cnt) {
	if (cnt == M) { // tree의 깊이가 M이면
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			arr[cnt] = i;
			backtracking(cnt + 1);
			visit[i] = false;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N>> M;
	backtracking(0);
}