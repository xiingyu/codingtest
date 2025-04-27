import sys

n,m = map(int,sys.stdin.readline().split())

relation = []
bacon = [float('inf') for _ in range(n+1)]
people = [x for x in range(1,n+1)]

for i in range(m) :
    relation.append(list(map(int, sys.stdin.readline().split())))

