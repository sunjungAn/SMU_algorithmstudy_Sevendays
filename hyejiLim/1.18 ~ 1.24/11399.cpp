#include <iostream>
# include <algorithm>
using namespace std;

int main(void) {
	int N;
	int p[1001];
	int sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p[i];
	}
	sort(p, p + N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++)
			sum += p[j]; // p[0], p[0]+p[1], p[0]+p[1]+p[2]... 순으로 더하기
	}
	cout << sum << "\n";
}