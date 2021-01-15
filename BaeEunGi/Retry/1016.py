#필요 개념: 에라토스테네스의 체, 소수 판정



check = [0]*1000001 #제곱수인지 제곱ㄴㄴ수인지 표현할 체크리스트를 미리 할당 시켜줌
a,b = map(int,input().split())
for i in range(2,b):
    if i*i > b: #제곱수가 MAX를 넘어가면 의미가 없으므로 break
        break
    start = i*i-a%(i*i) #MIN 값이 i^2보다 작은 경우 and 큰 경우
    if start == i*i: #MIN 값이 i^2와 같은 경우
        start = 0
    for j in range(start, b-a+1,i*i): #MIN~MAX 사이의 값들 중 제곱수로 나뉘어 떨어지는 수 들을 제외
        check[j]=1 #제곱수로 나누어 떨어지는 부분은 1로 바꿔줌
false = 0 #제곱ㄴㄴ수의 개수
for i in range(b-a+1):
    if check[i] == 0: #제곱ㄴㄴ수의 개수를 세누는 부분
        false = false+1
print(false)
