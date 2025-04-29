import sys

N,S,M = map(int,sys.stdin.readline().split())
v = list(map(int,sys.stdin.readline().split()))

#가능불가능 테이블 만든거임임
dp = [[0 for _ in range(M+1)] for _ in range(N+1)]
dp[0][S] = 1
for i in range(1, N+1) :
    for j in range(M+1) :
        if dp[i-1][j]>0:
            if 0<=j+v[i-1]<=M:
                dp[i][j+v[i-1]]=1
            if 0<=j-v[i-1]<=M:
                dp[i][j-v[i-1]]=1
answer = -1
for j in range(M+1) :
    if dp[N][j] == 1 :
        answer = max(answer, j)
print(answer)