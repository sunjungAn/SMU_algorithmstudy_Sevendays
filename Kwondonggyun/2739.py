
1)
a = int(input())
for i in range(1,10, 1):
    print("%d * %d = %d" %(a, i, a*i))



2)
a = int(input())
for i in range(1,10, 1):
    print("{} * {} = {}" .format(a, i, a*i))



3)
a = int(input())
for i in range(1,10, 1):
    print(f"{a} * {i} = {a*i}")
