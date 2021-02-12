#include <stdio.h>
int Factorial(int x);
int main(void)
{
	int N;
	scanf_s("%d", &N);

	printf("%d", Factorial(N));
}
int Factorial(int x) {
	if (x <= 1)
		return 1;
	else
		return x * Factorial(x - 1);
}
