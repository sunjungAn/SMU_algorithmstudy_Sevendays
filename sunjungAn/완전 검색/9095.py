T = int(input())
arr = []
arr.append(0)
arr.append(1)
arr.append(2)
arr.append(4)

for i in range(4, 12):
    arr.append(arr[i-1] + arr[i-2] + arr[i-3])
    
for i in range(T):
    n = int(input())
    print(arr[n])
    
