n = int(input())
l = [0,1,2,4,0,0,0,0,0,0,0]
a = []
for i in range(n):
    a.append(int(input()))
for i in range(4, max(a)+1):
    l[i] = l[i-1] + l[i-2] + l[i-3]
for i in a:
    print(l[i])
