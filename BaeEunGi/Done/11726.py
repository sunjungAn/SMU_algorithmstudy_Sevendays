n = int(input())
dp = [0 for i in range(n+1)]

if n <= 3 : print(n)
else:
    dp[1] = 1
    dp[2] = 2
    for i in range(3, n+1):
        dp[i] = dp[i-1] + dp[i-2]
    print(dp[i]%10007)
#하나하나 생각해보면 피보나치와 같은 수열이 나타남을 알 수 있다.(점화식)