import sys

N, K = map(int, sys.stdin.readline().split())
coin = list([])
ans = 0
for _ in range(N):
  a = int(sys.stdin.readline())
  coin.append(a)
coin.reverse()

for element in coin:
  b = int(K / element)
  ans = ans + b
  K = K - b * element
print(ans)
