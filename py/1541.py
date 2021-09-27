import sys
from collections import deque

N = list(sys.stdin.readline())
print(N)
stack = deque([])
for element in N:
  if element == '\n':
    break
  if element != '+' and element != '-':
    if len(stack) == 0:
      stack.push_back(element)
    elif stack.
