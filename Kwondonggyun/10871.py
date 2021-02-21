a, b = map(int, input().split())
c = list(map(int, input().split()))
for i in range(a):
    if c[i] < b:
        print(c[i], end='')




※ list(map(int, input().split())) : 리스트 입력받기
