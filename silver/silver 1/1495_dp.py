import sys

N,S,M = map(int,sys.stdin.readline().split())

v=list(map(int,sys.stdin.readline().split()))
dp=[[] for _ in range(N)]
if S+v[0] <= M :
    dp[0].append(S+v[0])
if S-v[0] >= 0 :
    dp[0].append(S-v[0])


results = [-1]

def dfs(start) :
    global dp, results
    # print(dp, start)
    if (start == N-1)  :
        return
    elif len(dp[start]) <= 0 :
        return
    for now in dp[start] :
        if (now + v[start+1] > M) and (now - v[start+1] < 0 ) :
            continue
        else :
            if now != -1 :
                flag0, flag1 = True,True
                if (now + v[start+1]) <= M :
                    dp[start+1].append(now + v[start+1])
                else :
                    flag0 = False
                if (now - v[start+1]) >= 0 :
                    dp[start+1].append(now - v[start+1])
                else :
                    flag1 = False
                
                if (flag0 or flag1) == False :
                    # results.append(-1)
                    return -1
                
            else :
                continue

    dfs(start+1)
            



dfs(0)
# print(dp)
if len(dp[-1]) >0 :
    print(max(dp[-1]))
else :
    print(-1)
# print(results)
