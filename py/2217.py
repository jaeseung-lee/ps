import sys

N = int(sys.stdin.readline())
A = list([])
for _ in range(N):
  temp = int(sys.stdin.readline())
  A.append(temp)
A.sort(reverse=True)
ans = A[0]
now = A[0]
for i in range(1, len(A)):
  temp = (i + 1) * A[i]
  if ans <= temp:
    ans = temp
print(ans)
