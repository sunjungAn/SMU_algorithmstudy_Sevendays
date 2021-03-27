    
high = []
sum = 0

for i in range(9):
    n = int(input())
    high.append(n)
    sum += n

high.sort()
lim = sum-100
for i in range(0,8):
    for j in range(i+1,9):
        if(high[i]+high[j] == lim):
            for k in range(0,9):
                if(k == i or k == j):
                    continue
                else : print(high[k])
            exit(0)
        
                    
    


        
