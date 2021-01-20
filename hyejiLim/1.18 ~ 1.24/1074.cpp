#include <iostream>
#include <cmath> // pow »ç¿ë 
using namespace std;

int N, r, c, total;
void recursion (int row, int col, int range) {
	if (row == r && col == c) {
		cout << total;
		return;
	}
	if (r < row + range && r >= row && c < col + range && c >= col) {
		recursion(row, col, range / 2);
		recursion(row, col + range / 2, range / 2);
		recursion(row + range / 2, col, range / 2);
		recursion(row + range / 2, col + range / 2, range / 2);
	}
	else {
		total += range * range;
	}

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> r >> c;
	recursion(0, 0, pow(2, N));
	return 0;

}