n = int(input())
W = []
H = []
R = []
for i in range(n):
    a, b = input().split()
    W.append(a)
    H.append(b)
for i in range(n):
    temp = 1
    for j in range(n):
        if W[i] < W[j] and H[i] < H[j]:
            temp = temp+1
    R.append(temp)
for i in range (n):
    print(R[i], end = ' ')
