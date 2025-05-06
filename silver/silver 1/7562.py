import sys
from collections import deque

n = int(sys.stdin.readline().strip())

dx = [-2,-2,-1,-1,1,1,2,2]
dy = [1,-1,2,-2,2,-2,1,-1]


for _ in range(n) :
    slant = int(sys.stdin.readline().strip())

    y,x = map(int,sys.stdin.readline().split())
    end =  list(map(int,sys.stdin.readline().split()))
    distance = 0
    Q = deque([(y,x,distance)])
    visited = set([y,x])
    

    while Q :
        y,x,dist = Q.popleft()
        # print(y,x,end,dist)
        if [y,x] == end :
            break
        
        for i in range(len(dx)) :
            nx = x + dx[i]
            ny = y + dy[i]

            if (0 <= nx < slant) and (0 <= ny < slant) :
                if (ny,nx) in visited :
                    continue
                else :
                    visited.add((ny,nx))
                    Q.append((ny,nx,dist +1))
    print(dist)
