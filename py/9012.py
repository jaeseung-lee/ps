import sys
from collections import deque

N = int(sys.stdin.readline())

for _ in range(N):
  target = str(sys.stdin.readline()).strip()
  stk = deque([])
  is_answer = True
  for ch in target:
    if ch == '(':
      stk.appendleft(ch)
    else:
      if len(stk) == 0 or stk.popleft() != '(':
        is_answer = False
        break
  if is_answer and len(stk) == 0:
    print("YES")
  else:
    print("NO")
