import sys
T = int(sys.stdin.readline().strip())
arr = []

def fibo(n) :
    global dp
    
    for i in range(3, n+1) :
        dp[i][0] = dp[i-1][0] + dp[i-2][0]
        dp[i][1] = dp[i-1][1] + dp[i-2][1]
    
for i in range(T) :
    arr.append(int(sys.stdin.readline().strip()))
maximum = max(arr)
dp = [[0,0] for _ in range((maximum+1) if maximum > 2 else 3)]
dp[0] = [1,0]
dp[1] = [0,1]
dp[2] = [1,1]
fibo(maximum)

for i in arr :
    print(" ".join(map(str,dp[i])))