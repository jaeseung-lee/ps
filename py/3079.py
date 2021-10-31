import sys

N, M = map(int, sys.stdin.readline().split())
T = list([])
TIME_MAX = 0
for _ in range(N):
  temp = int(sys.stdin.readline())
  T.append(temp)
  if TIME_MAX < temp:
    TIME_MAX = temp

start = 1
end = TIME_MAX * M

def bs(target_time):
  sum = 0
  global M
  for element in T:
    sum += target_time // element
  return sum >= M

while start < end:
  mid = (start + end) // 2
  if bs(mid):
    end = mid
  else:
    start = mid + 1

print(start)
