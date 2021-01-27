import sys
input=sys.stdin.readline

L = []
n = int(input().strip())

for i in range(n):
    a = str(input().strip())
    
    if ' ' in a:
        L.append(int(a[5:]))
        
    elif len(a)==5:
        if len(L) == 0:
            print(1)
        else:
            print(0)
            
    elif len(a) == 4:
        print(len(L))
        
    elif 't' in a:
        if len(L) == 0:
            print(-1)
        else:
            print(L[len(L)-1])
            
    else:
        if len(L) == 0:
            print(-1)
        else:
            print(L[len(L)-1])
            L.pop()
            
        
