import sys

n,k = map(int,sys.stdin.readline().split())
level = []

for _ in range(n) :
    level.append(int(sys.stdin.readline().strip()))

level.sort()

while k :
    level[0] += 1
    k -= 1
    level.sort()

print(min(level))