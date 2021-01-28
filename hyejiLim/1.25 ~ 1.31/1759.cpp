#include <iostream>
#include <algorithm>
using namespace std;
int L, C; // L개 알파벳 소문자, C가지 문자 종류
char alphbet[16];

void backtracking(int pos, string str, int mo, int ja) {
	if (str.size()==L && mo >= 1 && ja >= 2) {
		cout << str << "\n";
		return;
	}

	for (int i = pos; i < C; i++) {
		if (alphbet[i] == 'a' || alphbet[i] == 'u' || alphbet[i] == 'i' || alphbet[i] == 'o' || alphbet[i] == 'e')
			backtracking(i + 1, str + alphbet[i], mo + 1, ja);
		else
			backtracking(i + 1, str + alphbet[i], mo, ja + 1);
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> alphbet[i];
	}
	sort(alphbet, alphbet + C);
	backtracking(0, "", 0, 0);

}