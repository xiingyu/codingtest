import sys

n = int(sys.stdin.readline())
cnt = 0

while True :
    if n == 1 :
        break
    else :
        if n % 3 == 0 :
            n = n // 3
            cnt += 1
        elif (n-1) % 3 == 0 :
            n -= 1
            cnt += 1
        elif n % 2 == 0 :
            n = n // 2 
            cnt += 1
        else :
            n -= 1
            cnt += 1

print(cnt)