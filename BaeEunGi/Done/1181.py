n = int(input())
N = n
a = []
b = []
for i in range(n):
    w = input()
    if not w in a:
        a.append(w)
    else:
        N = N-1
a.sort()
a = sorted(a, key=len)
for i in range(N):
    print(a[i])
