#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;
long long dp[1000001];

int main(void)
{
	long long n;
	cin >> n;
	for(int i = 2; i<= n; i++)
	{
		dp[i] = i;
		long long num = i;
		if (num % 3 == 0)
			dp[num] = (min(dp[num], 1 + dp[num / 3]));
		if (num % 2 == 0)
			dp[num] = (min(dp[num], 1 + dp[num/2]));
		
			dp[num] = (min(dp[num], 1 + dp[num-1])); 
	}

	cout << dp[n] << '\n';
	
}