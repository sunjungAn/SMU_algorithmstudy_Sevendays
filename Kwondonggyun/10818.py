N=int(input())
a=list(map(int, input().split()))
max=a[0]
min=a[0]
for j in range(N):
    if a[j]>max:
        max=a[j]
    if a[j]<min:
        min=a[j]

print(min, max, sep=' ')


147116 KB   556 ms



import sys
input = sys.stdin.readline
N = input()

num_list = list(map(int, input().split()))
print(min(num_list), max(num_list), end='')

-> sys 내장함수 사용




N=int(input())
a=list(map(int, input().split()))
    
print(min(a), max(a), sep=' ')


147100 KB	484 ms
