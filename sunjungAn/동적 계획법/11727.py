n = int(input())

sum = 0
arr = []
arr.append(0)
arr.append(1)
arr.append(3)
arr.append(5)
for i in range(4, n+1):
    if(i%2==0):
        arr.append(arr[i-1]*2 +1)
    else:
        arr.append(arr[i-1]*2 -1)

print(arr[n]%10007)
    
    
