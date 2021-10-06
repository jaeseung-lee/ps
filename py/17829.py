import sys

N = int(sys.stdin.readline())

array = list([])
for _ in range(N):
  array.append(list(map(int, sys.stdin.readline().split())))

def d_q(len, x, y):
  global array
  if len == 2:
    temp = list([array[x][y], array[x + 1][y], array[x][y + 1], array[x + 1][y + 1]])
    temp.sort()
    return temp[2]
  else:
    next_len = int(len / 2)
    temp = list([d_q(next_len, x, y), d_q(next_len, x, y + next_len), d_q(next_len, x + next_len, y), d_q(next_len, x + next_len, y + next_len)])
    temp.sort()
    return temp[2]

print(d_q(N, 0, 0))
