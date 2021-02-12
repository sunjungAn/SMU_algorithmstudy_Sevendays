n = input()
a = input().split()
c = 0
for i in range(int(n)):
    temp = 0
    if a[i] == 1:
        continue
    for j in range(2, int(a[i])+1):
        if int(a[i])%j == 0:
            temp = temp+1
    if temp == 1:
        c = c+1
print(c)