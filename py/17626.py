import sys
import math

n = int(sys.stdin.readline())

def dfs(times, now, value):
  if times == now:
    if value == 0:
      print(now)
      exit(0)
    return

  i = 1
  while i<= math.sqrt(value):
    dfs(times, now + 1, value - i * i)
    i = i + 1
  return


ans = 1
while True:
  dfs(ans, 0, n)
  ans = ans + 1
