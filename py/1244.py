import sys

N = int(sys.stdin.readline())
S = list([-1])
S.extend(list(map(int, sys.stdin.readline().split())))
T = int(sys.stdin.readline())
for _ in range(T):
  a, b = map(int, sys.stdin.readline().split())
  if a == 1:
    index = 1
    while b * index < len(S):
      S[b * index] = S[b * index] ^ 1
      index = index + 1
  else:
    index = 1
    S[b] = S[b] ^ 1
    while b - index > 0 and b + index < len(S):
      if S[b - index] != S[b + index]:
        break
      else:
        S[b - index] = S[b - index] ^ 1
        S[b + index] = S[b + index] ^ 1
        index = index + 1
index = 0
for element in S:
  if element == -1:
    continue
  else:
    print(element, end=' ')
    index = index + 1
    if index == 20:
      index = 0
      print()
