import sys

n = int(sys.stdin.readline())

start = 0
end = 1
for _ in range(64):
  end = end * 2

while start < end:
  mid = (start + end) // 2
  if mid * mid > n:
    end = mid
  elif mid * mid <n:
    start = mid + 1
  else:
    print(mid)
    exit(0)

print(start)
