#include <iostream>
using namespace std;

int N;
int w, b = 0;
int arr[128][128];
void solve(int x, int y, int N) {
	int total = 0;
	for (int i = x; i < x + N; i++) {
		for (int j = y; j < y + N; j++) {
			if (arr[i][j])
				total++;
		}
	}


	if (total == N * N)
		b++;
	else if (!total)
		w++;
	else {
		solve(x, y, N / 2);
		solve(x + N / 2, y, N / 2);
		solve(x, y + N/2, N / 2);
		solve(x + N/2, y + N/2, N / 2);
	}

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	solve(0, 0, N);
	cout << w << "\n";
	cout << b << "\n";
}