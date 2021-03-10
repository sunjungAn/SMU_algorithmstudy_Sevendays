a=int(input())
for i in range(a):
    for j in range(0, a-i-1):
        print(' ', end='')
    for k in range(0, 2*i+1):
        print('*', end='')
    print()
