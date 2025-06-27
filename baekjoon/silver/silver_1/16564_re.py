import sys

n,k = map(int,sys.stdin.readline().split())
level = []

for _ in range(n) :
    level.append(int(sys.stdin.readline().strip()))

level.sort()
mini = level[0]


while k :
    mini = level[0]
    second = -1
    for idx,num in enumerate(level) :
        if num > mini :
            second = (num,idx)
            break
    add = 0
    for i in range(idx+1) :
        add += second[0] - level[i]

    if add>k :
        temp = k // (second[1])
        k = 0
        for i in range(idx+1) :
            level[i] += temp
    else :
        k -= add
        for i in range(idx+1) :
            level[i] += second[0] - level[i]



print(min(level))