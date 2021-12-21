import sys

D, K = map(int, sys.stdin.readline().split())

for A in range(1, 100001):
  for B in range(A, 100001):
    now = A + B
    a = A
    b = B
    for d in range(D - 3):
      a = b
      b = now
      now = now + a
      #print(f"{a} {b} {now}")
      if now >= 100001:
        break
    if now == K:
      print(A)
      print(B)
      exit(0)
