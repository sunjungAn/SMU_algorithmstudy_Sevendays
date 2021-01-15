check = [0]*1000001
a,b = map(int,input().split())
for i in range(2,b):
    if i*i > b:
        break
    start = i*i-a%(i*i)
    if start == i*i:
        start = 0
    for j in range(start, b-a+1,i*i):
        check[j]=1
ans = 0
for i in range(b-a+1):
    if check[i] == 0:
        ans = ans+1
print(ans)
