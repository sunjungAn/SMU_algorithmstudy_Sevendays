n = int(input())
N = 100
if n<100:
    print(n)
elif n<111:
    print(99)
elif n<123:
    print(100)
else:
    for i in range(122,n+1):
        a = i//100
        b = (i-(a*100))//10
        c = i%10
        if (b-a) == (c-b):
            N = N+1
    print(N)
