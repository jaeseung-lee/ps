import sys
from collections import deque
dir = [[1, 0], [-1, 0], [0, -1], [0, 1]]
T = int(sys.stdin.readline())
for t in range(T):
    M, N, K = map(int, sys.stdin.readline().split())
    Board = [[0 for x in range(M)] for y in range(N)]
    for k in range(K):
        X, Y = map(int, sys.stdin.readline().split())
        Board[Y][X] = 1
    count = 0
    for y in range(N):
        for x in range(M):
            if Board[y][x] == 1:
                count = count + 1
                q = deque([])
                q.append((y, x))
                Board[y][x] = -1
                while len(q) != 0:
                    now_y, now_x = q.popleft()
                    for d in range(4):
                        next_y = now_y + dir[d][0]
                        next_x = now_x + dir[d][1]
                        if 0 <= next_y < N and 0 <= next_x < M:
                            if Board[next_y][next_x] == 1:
                                q.append((next_y, next_x))
                                Board[next_y][next_x] = -1
    print(count)
