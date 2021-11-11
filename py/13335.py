import sys
from collections import deque
from typing import BinaryIO

n, w, L = map(int, sys.stdin.readline().split())
A = list(map(int, sys.stdin.readline().split()))
Bridge = deque()
for _ in range(w):
    Bridge.append(0)
now_weight = 0
ans = 0
index = 0
while index < n:
    if now_weight + A[index] <= L:
        Bridge.append(A[index])
        now_weight = now_weight + A[index]
        index = index + 1
    else:
        Bridge.append(0)
    now_weight = now_weight - Bridge.popleft()
    if now_weight != 0:
        ans = ans + 1
while now_weight != 0:
    now_weight = now_weight - Bridge.popleft()
    ans = ans + 1
print(ans)
