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


bacon = [float('inf') for _ in range(n+1)]
history = [[0 for _ in range(n+1)]for _ in range(n+1)]
for start in people :
    for end in people :
        Q = deque([])
        distance = [-1 for _ in range(n+1)]
        distance[start] = 0
        if start == end :
            continue
        else :
            if history[end][start] != 0 :
                history[start][end] = history[end][start]
                continue
            Q.append(start)
            
            while Q :
                now = Q.popleft()
                for future in dic[now] :
                    # print(start, end, dic[now], future, distance)
                    if future == end :
                        distance[future] = distance[now] + 1
                        Q = deque()
                        break
                    elif distance[future] == -1 :
                        distance[future] = distance[now] + 1
                        Q.append(future)
            history[start][end] = distance[end]

    bacon[start] = sum(history[start])
# print(history)
for person,i in enumerate(bacon) :
    if i == min(bacon) :
        print(person)
        break