a = int(input())
for i in range(a):
    for j in range(i+1):
        print('*', end='')
    for k in range(2*a-2*i-2):
        print(' ', end='')
    for l in range(i+1):
        print('*', end='')
    print()
for i in range(a):
    for j in range(a-i-1):
        print('*', end='')
    for k in range(2*i+2):
        print(' ', end='')
    for l in range(a-i-1):
        print('*', end='')
    print()
