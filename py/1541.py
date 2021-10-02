import sys
from collections import deque

N = list(sys.stdin.readline())
q = deque([])
temp = 0
num = 0
for element in N:
  if element == '\n':
    break
  if element != '+' and element != '-':
    temp = temp * 10 + int(element)
  elif element == '+':
    num = num + temp
    temp = 0
  else:
    q.append(num + temp)
    num = 0
    temp = 0
q.append(num + temp)
ans = 0
if len(q) > 0:
  ans = q.popleft()

while len(q) > 0:
  ans = ans - q.popleft()

print(ans)
