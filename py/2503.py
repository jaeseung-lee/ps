import sys

N = int(sys.stdin.readline())
number = list([True for i in range(1000)])
for index in range(100, 1000):
  now = str(index)
  if now[0] == '0' or now[1] == '0' or now[2] == '0':
    number[index] = False
  if now[0] == now[1] or now[1] == now[2] or now[2] == now[0]:
    number[index] = False

for _ in range(N):
  n, strikes, balls = map(int, sys.stdin.readline().split())
  for index in range(100, 1000):
    if not number[index]:
      continue
    now_ball = 0
    now_strike = 0
    for i in range(3):
      if str(index)[i] == str(n)[i]:
        now_strike = now_strike + 1
      else:
        for j in range(3):
          if str(index)[j] == str(n)[i]:
            now_ball = now_ball + 1
    if not (now_ball == balls and now_strike == strikes):
      number[index] = False

ans = 0
for index in range(100, 1000):
  if number[index]:
    ans = ans + 1
print(ans)
