import sys

N = int(sys.stdin.readline())
times = list([])
now = 0
ans = 0
for _ in range(N):
  a, b = map(int, sys.stdin.readline().split())
  b - a
  times.append((b, a))
times.sort()

for element in times:
  a, b = element
  if b < now:
    continue
  else:
    now = a
    ans = ans + 1
print(ans)
