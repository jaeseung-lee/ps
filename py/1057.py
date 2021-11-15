import sys
from collections import deque

N, kim, im = map(int, sys.stdin.readline().split())
q = deque([ i for i in range(1,N+1)])
round = 0
while (not len(q) == 1):
  left = q.popleft()
  right = q.popleft()
  if left > right:
    q.appendleft(right)
    q.append(left)
  else:
    round = round + 1
    if (left == kim and right == im) or (left == im and right == kim):
      break
    elif left == kim or left == im:
      q.append(left)
    elif right == kim or right == im:
      q.append(right)
    else:
      q.append(left)
ans = 0
while round > 0:
  ans = ans + 1
  round = round - N // 2
  N = N - N // 2
print(ans)
