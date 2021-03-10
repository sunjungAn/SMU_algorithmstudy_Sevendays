a = int(input())
for i in range(a):
    for k in range(0, i):
        print(' ', end='')
    for j in range(0, 2*a-(2*i+1)):
        print('*', end='')
    print()
