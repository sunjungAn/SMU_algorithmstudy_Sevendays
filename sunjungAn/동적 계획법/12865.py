import sys

N, K = map(int, input().split())
array = [[0,0]]
knapsack = [[0 for _ in range(K+1)] for _ in range(N+1)]

for _ in range(N):
    array.append(list(map(int, input().split())))


for i in range(1, N+1):
    W = array[i][0]
    V = array[i][1]

    for j in range(1, K+1):
        if j<W:
            knapsack[i][j] = knapsack[i-1][j]

        else:
            knapsack[i][j] = max(V+knapsack[i-1][j-W], knapsack[i-1][j])

print(knapsack[N][K])    
    
