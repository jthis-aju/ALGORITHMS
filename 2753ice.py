import sys
from collections import deque

n,m=map(int, sys.stdin.readline().split())
l = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
direction = [(-1, 0), (1, 0), (0, 1), (0, -1)]
year = 0

def bfs(a, b):
    nex = deque([(a, b)]) # 왼쪽에서 뽑을 때는 deque가 효율적
    vis[a][b] = 1
    while nex:
        x, y = nex.popleft()
        #vis[x][y] = 1
        for k, q in direction:
            dx = x + k
            dy = y + q
            if l[dx][dy] == 0:
                vis[x][y] += 1
            if vis[dx][dy] == 0 and l[dx][dy]:
                nex.append((dx, dy))
                vis[dx][dy] = 1

while True:
    seg = 0
    vis = [[0] * m for _ in range(n)]
    for i in range(1,n-1):
        for j in range(1,m-1):
            if vis[i][j] == 0 and l[i][j]:
                bfs(i,j)
                seg += 1
    for i in range(1, n - 1):
        for j in range(1, m - 1):
            if l[i][j]:
                l[i][j] = max(l[i][j] - vis[i][j] + 1, 0)
    if seg > 1:
        break
    elif seg == 0:
        year = 0
        break
    # print(l)
    year += 1
print(year)