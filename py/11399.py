import sys

N = int(sys.stdin.readline())
array = list(map(int, sys.stdin.readline().split()))
array.sort()
l = N
ans = 0
for element in array:
  ans = ans + element * l
  l = l - 1
print(ans)
