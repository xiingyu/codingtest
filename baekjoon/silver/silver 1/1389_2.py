import sys
from collections import deque

n,m = map(int,sys.stdin.readline().split())
relations = []
people = [x for x in range(1,n+1)]
dic = {x : [] for x in range(1,n+1)}

for i in range(m) :
    relations.append(list(map(int, sys.stdin.readline().split())))
    dic[relations[-1][0]].append(relations[-1][1])
    if relations[-1][0] not in dic[relations[-1][1]] :
        dic[relations[-1][1]].append(relations[-1][0])
del relations

Q = deque([])
# visited = [False for _ in range(n+1)]

def true_cnt(arr) :
    cnt = 0
    for i in arr :
        if i == True :
            cnt +=1
    return cnt

bacon = [float('inf') for _ in range(n+1)]
history = [[0 for _ in range(n+1)]for _ in range(n+1)]
for start in people :
    individual_bacon = [0 for _ in range(n+1)]
    for end in people :
        visited = [False for _ in range(n+1)]
        if start == end :
            continue
        else :
            Q.append(start)
            visited[start] = True
            while Q :
                now = Q.popleft()
                visited[now] = True
                if now == end :
                    break
                else :
                    for future in dic[now] :
                        if visited[future] == False :
                            Q.append(future)
                        else :
                            pass
            individual_bacon[end] = true_cnt(visited) -1
            history[start][end] = true_cnt(visited) -1

    bacon[start] = sum(individual_bacon)

for person,i in enumerate(bacon) :
    if i == min(bacon) :
        print(person)
        break