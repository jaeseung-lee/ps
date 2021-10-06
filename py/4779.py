import sys

def solve(maxsize, nowsize):
  if nowsize == 1:
    print("-", end='')
  else:
    nextsize = int(nowsize/3)
    solve(maxsize, nextsize)
    print_empty(nextsize)
    solve(maxsize, nextsize)

def print_empty(count):
  for i in range(count):
    print(" ", end='')
while True:
  try:
    N = int(sys.stdin.readline())
    x = 1
    for _ in range(N):
      x = x*3
    solve(x, x)
    print()
  except:
    break
