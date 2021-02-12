#include <stdio.h>
#include <string.h>
int main(void)
{
	char a[101], i;
	int b[26], j;
	scanf_s("%s", a, sizeof(a));
	for (i = 0; i < 26; i++)
		b[i] = -1;

	for (i = 'a'; i <= 'z'; i++) {
		for (j = 0; j < strlen(a); j++) {				// j < 100 : X
			if (a[j] == i) {					// j < strlen(a) : O
				b[i - 97] = j;
				break;
			}
		}
	}
	for (j = 0; j < 26; j++) {
		printf("%d ", b[j]);
	}
}
