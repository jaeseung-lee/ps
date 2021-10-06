import sys

N = int(sys.stdin.readline())
array = list([])
for _ in range(N):
  temp = list(map(int, sys.stdin.readline().split()))
  array.append(temp)

blue = 0
white = 0

def d_q(length, x, y):
  global blue
  global white
  color = array[x][y]
  for t_x in range(x, x + length):
    for t_y in range(y, y + length):
      if color != array[t_x][t_y]:
        next_length = int(length/2)
        d_q(next_length, x, y)
        d_q(next_length, x+next_length, y)
        d_q(next_length, x, y+next_length)
        d_q(next_length, x+next_length, y+next_length)
        return
  if color == 1:
    blue = blue + 1
  else:
    white = white + 1


d_q(N, 0, 0)
print(white)
print(blue)
