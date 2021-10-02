import sys

T = int(sys.stdin.readline())
for _ in range(T):
  N = int(sys.stdin.readline())
  array = list([])
  for _ in range(N):
    a, b = map(int,sys.stdin.readline().split())
    array.append((a, b))
  array.sort()
  dp = list([])
  for i in range(N):
    c, d = array[i]
    dp.append(1)
    for j in range(0, i):
      a, b = array[j]
      if b > d and dp[j] + 1 > dp[i]:
        dp[i] = dp[j] + 1
  print(max(dp))
