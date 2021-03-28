
N = int(input())
arr = []
arr = list(map(int, input().split()))
base = []
count = 0

for i in range(1, N): 
    if(arr[N-i] > arr[N-i-1]):
        base.append(arr[N-i])
        base.sort()
        for k in range(len(base)):
            if(base[k] > arr[N-i-1]):
                temp = base[k]
                base[k] = arr[N-i-1]
                arr[N-i-1] = temp
                for i in range(N-len(base)):
                    print(arr[i] , end =' ')
                for j in range(len(base)):
                    print(base[j], end = ' ')
                exit(0)
                
    else :
        base.append(arr[N-i])
        count = count+1

if(count == N-1):
    print(-1)
#else :
#    for i in range(N-len(base)):
#        print(arr[i] , end =' ')
#    for j in range(len(base)):
#        print(base[j], end = ' ')


        
    
    
