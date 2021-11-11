import sys
from collections import deque

N, K = map(int, sys.stdin.readline().split())

q = deque([i+1 for i in range(N)])
index = 1
ans = list([])
while len(q) > 0:
    if index == K:
        ans.append(q.popleft())
        index = 1
    else:
        index = index + 1
        q.append(q.popleft())

print(f"<{ans[0]}", end='')
for index in range(1, N):
    print(f", {ans[index]}", end='')
print(">")
