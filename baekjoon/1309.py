import sys

N = int(sys.stdin.readline().strip())
visited = [[False for _ in range(N)] for _ in range(2)]
coord = []
avail = N -1
cnt = 0

results = []
def dfs(lion) :
    global results, cnt, coord, visited
    
    if len(coord) >= lion :
        temp_arr = coord[:]
        temp_arr.sort()
        # print(temp_arr)
        if temp_arr in results :
            # print("repreated")
            pass
        else :
            # print("counted")
            results.append(temp_arr[:])
            cnt += 1
        return
    for i in range((coord[-1][0] if len(coord) != 0 else 0),N*2) :
        if i >=N :
            j = 1
            i -= N
            if visited[j][i] == False :
                if (visited[0][i] == True) or (visited[j][i + (1 if i != N-1 else 0)] == True) or (visited[j][i - (1 if i != 0 else 0)] == True) :
                    continue
                visited[j][i] = True
                coord.append([j,i])
            else :
                continue
        else :
            j=0
            if visited[j][i] == False :
                if (visited[1][i] == True) or (visited[j][i + (1 if i != N-1 else 0)] == True) or (visited[j][i - (1 if i != 0 else 0)] == True) :
                    continue
                visited[j][i] = True
                coord.append([j,i])
            else :
                continue
        dfs(lion)
        # if coord in results :
        #     pass
        # else :
        #     results.append([coord])
        coord.pop()
        visited[j][i] = False
        
            

for lions in range(avail+2) :
    if lions == 0 :
        cnt += 1
    elif lions == 1 :
        cnt += N*2
    elif (lions == (avail+1)) :
        cnt += 2
    else :
        dfs(lions)

print(cnt % 9901)
    