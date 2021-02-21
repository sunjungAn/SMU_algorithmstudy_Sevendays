N=int(input())
count=0
a=N
while True:
    if a==(N%10+N//10)%10+(N%10)*10:
        count+=1
        print(count)
        break
    else:
        N=(N%10+N//10)%10+(N%10)*10
        count+=1
