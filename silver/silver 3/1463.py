import sys
from collections import deque

n = int(sys.stdin.readline().strip())

distance = 0
next = 0

Q = deque([(n,distance)])
visited = set([n])

while Q :
    current, dist = Q.popleft()
    if current == 1 :
        print(dist)
        exit()
    
    for i in range(3) :
        if i == 0 :
            if current % 3 == 0 :
                next = current//3
                if next not in visited :
                    visited.add(next)
                    Q.append((next,dist+1))
        elif i == 1 :
            if current % 2 == 0 :
                next = current//2
                if next not in visited :
                    visited.add(next)
                    Q.append((next,dist+1))
        else :
            next = current - 1
            if 0<next:
                if next not in visited :
                    visited.add(next)
                    Q.append((next,dist+1))