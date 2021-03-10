a = int(input())
for i in range(a):
    for j in range(i):
        print(' ', end='')
    for k in range(2*a-2*i-1):
        print('*', end='')
    print()
for i in range(a-1):
    for j in range(a-i-2):
        print(' ', end='')
    for k in range(2*i+3):
        print('*', end='')
    print()
