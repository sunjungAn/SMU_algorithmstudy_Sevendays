n = int(input())
arr = []
arr = list(map(int, input().split()))
brr = []
brr.append(0)
    
for i in range(1, n+1):
    brr.append(max(brr[i-1]+arr[0], arr[i-1]))

for k in range(2, int(n/2)+1):
    for i in range(1, n+1):
        if(i> k): # 1, 2, 3, 4
            brr[i]= max(brr[i], brr[i-k]+arr[k-1])


print(brr[n])
