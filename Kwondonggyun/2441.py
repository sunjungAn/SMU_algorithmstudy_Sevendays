a=int(input())
for i in range(a):
    for j in range(0, i):
        print(' ', end='')
    for k in range(0, a-i):
        print('*', end='')
    print()
