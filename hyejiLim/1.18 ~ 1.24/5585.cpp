#include <iostream>
using namespace std;

int main() {
	int money;
	int coin[] = { 500, 100, 50, 10, 5, 1 };
	int answer = 0;

	cin >> money;

	int change = 1000 - money;

	for (int i = 0; i < sizeof(coin); i++) {
		while (change - coin[i] >= 0) {
			change -= coin[i];
			answer++;
		}
		if (change == 0)
			break;
	}

	cout << answer;
}