import sys

X, Y = map(int, sys.stdin.readline().split())
if (X * 99) <= (100 * Y):
  print("-1")
else:
  Z = (100*Y) // X
  N = (X + X * Z - 100 * Y) // (99 - Z)
  if (X + X * Z - 100 * Y) % (99 - Z) == 0:
    print(N)
  else:
    print(N+1)
