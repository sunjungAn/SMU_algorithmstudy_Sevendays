< 1st >
a=int(input())
n=0
for i in range(a):
    for j in range(a-i-1):
        print(' ', end='')
    for k in range(1):
        print('*', end='')
    for l in range(2*i-1):
        print(' ', end='')
    for m in range(0,n):
        print('*', end='')
    n=1
    print()


< 2nd >
a = int(input())
print(' '*(a-1)+'*')
for i in range(a-1):
    print(' '*(a-i-2)+'*'+' '*(2*i+1)+'*')
