#include <stdio.h>
#include <stdlib.h>         // abs 함수
#include <math.h>           // sqrt, pow 함수
int main(void)
{
	int T, result;
	int x1, y1, r1, x2, y2, r2;
	double d;
	scanf_s("%d", &T);

	while (T > 0) {
		scanf_s("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

		if (d == 0 && r1 == r2)
			result = -1;

		else if (d < (double)r1 + (double)r2 && abs(r1-r2) < d)
			result = 2;

		else if (d == abs(r1-r2) || d == (double)r1 + (double)r2)
			result = 1;

		else
			result = 0;

		T--;
		printf("%d\n", result);
	}
}
