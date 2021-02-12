  
#include <stdio.h>
int hannum(int x) {
	int num = x;
	int result = 0;
	int count = 99;
	
	if (num < 100) {                        // 1자리, 2자리수의 한수 : 자기 자신
		result = num;
	}
	else if (num < 111 && num > 99) {       // 100 ~ 110까지의 수 : 100 ~ 110까지 한수 X -> 무조건 99개
		result = 99;
	}
	else if (num > 110) {                   // 111이상 ~ : 자리수로 나눠 한수인지 판단
		while (num > 110) {
			if (num / 100 - ((num - num % 10) / 10) % 10 == ((num - num % 10) / 10) % 10 - num % 10) {
				count++;
			}
			num--;
		}
		return count;
	}
	return result;
}

int main(void)
{
	int n;
	scanf_s("%d", &n);
	
	printf("%d\n", hannum(n));
}
