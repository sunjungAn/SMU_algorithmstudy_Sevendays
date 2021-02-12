#include <stdio.h>
int Fibo(int x);
int main(void)
{
	int n;
	scanf_s("%d", &n);

	printf("%d", Fibo(n));
}
int Fibo(int x) {
	if (x == 0)
		return 0;
	else if (x == 1)
		return 1;

	return Fibo(x - 1) + Fibo(x - 2);
}
