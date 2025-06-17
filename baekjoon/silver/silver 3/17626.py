import sys
n = int(sys.stdin.readline().strip())

square = int(n **0.5)

dp = [0]

for i in range(1,square+1) :
    dp.append(i**2)
    
flag = False
if n in dp :
    print(1)
    flag = True
else :
    if flag == False :
        for i in range(1,square+1) :
            if flag == False :
                for j in range(i,square+1) :
                    if ((dp[i] + dp[j]) == n) :
                        print(2)
                        flag = True
                        break
    if flag == False :
        for i in range(1,square+1) :
            if flag == False :
                for j in range(i, square+1) :
                    if flag == False :
                        for k in range(j,square+1) :
                            if ((dp[i] + dp[j] + dp[k]) == n) :
                                print(3)
                                flag = True
                                break
                    
        
    if flag == False :
        print(4)