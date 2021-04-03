n = int(input())

arr = []
arr.append(0)
arr.append(1)
arr.append(2)
arr.append(4)

for i in range(4, 1000001):
    arr.append((arr[i-2]+arr[i-1]+arr[i-3]) % 1000000009)

for i in range(n):
    k = int(input())
    print(arr[k])
