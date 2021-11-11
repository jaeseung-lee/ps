import sys

N = int(sys.stdin.readline())
board = list([list([False for i in range(101)]) for j in range(101)])
for _ in range(N):
    X, Y = map(int, sys.stdin.readline().split())
    for i in range(10):
        for j in range(10):
            board[X+i][Y+j] = True

ans = 0
for r in range(1, 101):
    for c in range(1, 101):
        if board[r][c]:
            ans = ans + 1
print(ans)
