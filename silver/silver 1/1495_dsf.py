import sys

N,S,M = map(int,sys.stdin.readline().split())

v=list(map(int,sys.stdin.readline().split()))

# visited = [False for _ in range(N+1)]
results = [-1]

def dfs(start,vol) :
    # print(start,vol)
    global results
    if start == N :
        if vol >= max(results) :
            results[-1] = vol
        return vol
    future_vol = 0
    for i in range(2) :
        # print(start,vol, i)
        if i == 0 :
            if vol+v[start] > M and vol-v[start] < 0 :
                return -1
            elif vol+v[start] <= M :
                future_vol = vol + v[start]
            elif vol-v[start] >= 0 :
                continue
        elif i == 1:
            if vol+v[start] > M and vol-v[start] < 0 :
                return -1
            elif vol-v[start] >= 0 :
                future_vol = vol - v[start]
            elif vol+v[start] <= M :
                return -1
    

        dfs(start+1,future_vol)        

    return max(results)
dfs(0,S)
print(max(results))
# print(results)
